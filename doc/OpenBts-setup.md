Integration of Serval DNA with OpenBTS
======================================
[Serval Project][], May 2013

The quick start guide that came with the RangeNetworks 5150 unit provided
sufficient information to turn it on and configure it.  While we were setting
up basic configuration for the unit, we unplugged the radio hardware to ensure
that it would not cause any unexpected transmissions.  However the Quick Start
Guide was slightly incorrect; the unit booted with IP address 192.168.0.22
instead of 192.168.0.21.

Note: The simplest methods for modifying OpenBTS config are via the CLI command
line or web interface.  However if the configuration is invalid this may cause
OpenBTS to fail to start. In which case you will have no choice but to edit the
config directly in the sqlite database `/etc/OpenBTS/OpenBTS.db`.

To reduce the risk of interference for bench testing, set the attenuation to
the highest value that still allows phones to discover and connect to the
network, eg:

    $ ./CLI
    OpenBTS> power 60 60
    OpenBTS> [Ctrl-D, A]
    $

Follow the quick start quide to provision two handsets for testing.

Download the [Serval DNA][] and VoMP Asterisk channel driver source code:

    $ git clone git://github.com/servalproject/serval-dna.git
    $ git clone git://github.com/servalproject/app_servaldna.git
    $

The OpenBTS unit is running Ubuntu 10.4.  Build the Serval DNA executable by
following the instructions in [serval-dna/INSTALL.md](../INSTALL.md).

Follow the build, installation and configuration instructions in
[app\_servaldna/README.md][], using `/var/serval-node` as the instance
directory.

XXX Set up the server to start [Serval DNA][] on boot. This can be achieved by
adding a "servald start" command to /etc/rc.local, or copying the .


XXX Copy the sample servald configuration to resolve OpenBTS phone numbers (you may
need to correct the path to `num2sip.py`):

    $ cp conf_adv/serval.conf /var/serval-node/

Add an identity to servald. If you don't create one manually, and identity will
be created when you first start the server.  Take note of this public key for
later use while verifying that everything is working correctly:

    $ servald keyring add
    sid:[SID of BTS unit]
    did:[default phone number]
    $

Configure a meaningful name to display to other Serval devices. The phone
number you specify here will be dialed when a user attempts to call this
instance of servald from their list of peers.  You may wish to configure this
to dial an echo test extension in Asterisk:

    $ servald set did [SID of BTS unit] [phone number] [name]
    $

Make sure all services are re-started.


Functional testing
------------------

### OpenBTS phone to local Asterisk test number ###

The supplied configuration includes extension 10411 for an echo test, call this
number from one of the provisioned phones.

### OpenBTS phone to another local OpenBTS phone ###

### Remote number resolution of OpenBTS numbers ###

On another machine running servald with a network path to the OpenBTS unit:

    $ servald dna lookup [number]
    sid://[SID of BTS unit]/[ext]:[ext]:
    $

### Remote call to local Asterisk test number ###

Set the phone number of a servald identity to an Asterisk extension configured
with an echo test. Then call this device from a serval phone using the peer
list.

### OpenBTS call to remote serval phone ###

### Remote phone call to OpenBTS phones ###


[Serval Project]:
[Serval DNA]:
[OpenBTS]:
[app\_servaldna/README.md]:
