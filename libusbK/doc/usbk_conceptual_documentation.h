/*! \mainpage libusbK Home

<TABLE>
<TR>
	<TH><B>libusbK Author</B>: <TT>Travis Lee Robinson</TT></TH>
	<TH><B>Version</B>: <TT>3.0</TT></TH>
	<TH><B>Date</B>: <TT>2011</TT></TH>
</TR>
</TABLE>
<IMG src="ftv2folderclosed.png" style="display: none" />
<IMG src="ftv2folderopen.png" style="display: none" />
<IMG src="ftv2mnode.png" style="display: none" />
<IMG src="ftv2pnode.png" style="display: none" />
<IMG src="ftv2mlastnode.png" style="display: none" />
<IMG src="ftv2plastnode.png" style="display: none" />
<IMG src="ftv2vertline.png" style="display: none" />
<IMG src="ftv2node.png" style="display: none" />
<IMG src="ftv2blank.png" style="display: none" />

- \subpage usbk_about
  <BR>Explanation of the libusbK project, the user mode library, and its \ref usbk_drivers.
  <HR>
- \subpage usbk_installing
  <BR>Methods for installing the libusbK binaries and drivers.
  <HR>
- \subpage usbk_usage
  <BR>Where to begin and how to get started writing your new libusbK based application.
  <HR>
- \subpage usbk_building
  <BR>Methods for building the libusbK user mode library and driver from source code.
  <HR>

*/

/*! \addtogroup genk UsbK General
* \brief \ref genk \copybrief lusbk_common.h
*
*  @{
*/

/*! @} */

/*! \addtogroup usbk UsbK Core API
* \brief \ref usbk \copybrief lusbk_usb.h
*
*  @{
*/

/*! @} */

/*! \addtogroup lstk Device List API
* \brief \ref lstk \copybrief lusbk_device_list.h
*
*  @{
*/

/*! @} */

/*! \addtogroup ovlk OverlappedK API
* \brief \ref ovlk \copybrief lusbk_overlapped.h
*
*  @{
*/

/*! @} */

/*! \addtogroup drvk Dynamic Driver API
* \brief \ref drvk \copybrief lusbk_dynamic.h
*
*  @{
*/

/*! @} */

//! Explanation of the libusbK project, the user mode library, and its \ref usbk_drivers
/*! \page usbk_about About

libusbK can be separated into two major components:
- A Windows user mode USB library (libusbK.dll)
- A Windows kernel mode USB driver (libusbK.sys)

\section usbk_about_dll libusbK.dll (libusbK user library)
libusbK.dll is a generic user mode usb library for
the Microsoft Windows Operating System family. (Windows XP and up)

Windows 2000 is currently not supported by the release builds or driver installer packages
but can still be achieved with manual builds and custom driver installations.

\note
The libusbK library allows developers to target multiple drivers using the same set of api function declarations.

\par
\subsection usbk_drivers Supported Drivers
The following usb kernel drivers are supported by the libusbK library:
- \b libusbK.sys
- \b libusb0.sys
  - Using the api functions exported by the libusbK library (functions beginning with with \b UsbK_)
  - Using dynamically loaded functions based on the devices driver type. see \ref drvk
- \b WinUSB.sys
  - Using dynamically loaded functions based on the devices driver type. see \ref drvk

\par
\subsection usbk_winusb_compat WinUSB Compatibility Layer
The libusbK library includes a \c Winusb.dll compatiblity layer.
This makes libusbK a drop-in replacement for an existing WinUSB application.
Developers can make use of this functionality in two ways:
- Using the \b WinUsb_ prefixed function which are directly exported by libusbK.dll
  - Usage of the \c WinUsb_ prefixed functions is intended for developers who want to switch away from the
    \c WinUSB.sys driver without modifying application code.
  - The \c WinUsb_ prefixed functions must \b not be used for devices installed with the WinUSB.sys driver.
  - The \c WinUsb_ prefixed functions are identical to the exported \c UsbK_ prefixed functions, thus \b must
    be installed with either the \c libusbK.sys or \c libusb0.sys driver.
- Using the \ref drvk
  - This option allows users to target any of the \ref usbk_drivers
    but requires small modifications to the applications source code.

\section usbk_about_sys libusbK.sys (libusbK kernel driver)

libusbK.sys is a KMDF based usb device kernel driver for
the Microsoft Windows Operating System family. (Windows XP and up)

Windows 2000 is currently not supported by the release builds or driver installer packages
but can still be achieved with manual builds and custom driver installations.

The libusbK kernel driver uses an extended libusb-win32 (libusb0.sys) compatible
driver api and provides higher-level functionality when compared to libusb0.sys.

libusbK.sys advantages when compared to libusb0.sys:
- Winusb-like power management
- Winusb-like pipe policies
- Driver-level asynchronous transfer timeouts
- Improved isochronous transfer support
- Newer, more robust KMDF based design

libusbK.sys disadvantages when compared to libusb0.sys:
- Does not support multiple configurations
- Does not support a "filter driver" mode
- Significantly larger device driver installation packages
- Less tolerant of usb devices which or not fully compliant with usb specifications

The following user mode usb libraries support the \c libusbK.sys kernel driver:
- \b libusbK.dll
- \b libusb0.dll

*/

//! Methods for installing the libusbK binaries and drivers.
/*! \page usbk_installing Installation
*/

//! Methods for building the libusbK user mode library and driver from source code.
/*! \page usbk_building Building from source
- \subpage usbk_building_make_cmd
  <BR>Building and packaging with the automated MSDOS script \b make.cmd.
  <HR>
- \subpage usbk_building_wdk
  <BR>Building with a <A href="http://msdn.microsoft.com/en-us/windows/hardware/gg487463">Windows Driver Kit</A>.
  <HR>
- \subpage usbk_building_msvc
  <BR>Building with Microsoft Visual Studios 2008/Express Editions.
  <HR>

*/

//! Building and packaging with the automated MSDOS script \b make.cmd.
/*! \page usbk_building_make_cmd Building with make.cmd
*
* On this page:
* - \ref usbk_building_make_cmd_about
*   - \ref usbk_building_make_cmd_about_features
*   - \ref usbk_building_make_cmd_about_requirements
* - \ref usbk_building_make_cmd_config
*   - \ref usbk_building_make_cmd_config_wdk
* - \ref usbk_building_make_cmd_usage
*   - \ref usbk_building_make_cmd_usage_syntax
*   - \ref usbk_building_make_cmd_usage_commands
* - \ref usbk_building_make_cmd_usage_examples
*   - \ref usbk_building_make_cmd_usage_example_build
*   - \ref usbk_building_make_cmd_usage_example_dist
*   - \ref usbk_building_make_cmd_usage_example_clean
* - \ref usbk_building_make_cmd_config_examples
*   - \ref usbk_building_make_cmd_config_example_make_cfg
*   - \ref usbk_building_make_cmd_config_example_make_versions
*
* <HR>
* \section usbk_building_make_cmd_about About
* \b make.cmd is a MSDOS (extended mode) batch file which fully automates several tasks.
* 
* \note
* \b make.cmd is non-specific to libusbK.
* It is fully configurable from its \b make.cfg configuration.
*
* \subsection usbk_building_make_cmd_about_features Features
*  - Generates WDK "sources" from custom ".sources" file templates
*    - By design, WDK allows only one project (or sources file) per directory.
*      The \b make.cmd custom ".sources" file templates eliminate this restriction.
*    - Provides pre-tagging functionality for WDK "sources" files.
*  - Code signing
*  - INNO setup installer creation
*  - Version control
*  - Binary package creation
*  - Source package creation
*  - Regular expression based cleaning
*  - Source code re/formatting
* 
* \subsection usbk_building_make_cmd_about_requirements Requirements
*  - <A href="http://msdn.microsoft.com/en-us/windows/hardware/gg487463.aspx">Windows Driver Kit</A> (6001.18002 or greater)
*  - <A href="http://www.jrsoftware.org/isdl.php">INNO Setup</A>
*  - <A href="http://astyle.sourceforge.net/">Astyle</A> (optional)
*  - 7Zip (included is src package)
*
*
* <HR>
* \section usbk_building_make_cmd_config Initial Setup and Configuration
* After installing the required software, make.cfg must be configured to use it.
* Generally this only requires modifying the WDK SETUP section so make.cmd can locate your WDK installation.
* See the comments in \b make.cfg for more information.
*
* \subsection usbk_building_make_cmd_config_wdk Automatically configuring make.cmd with a WDK installation
* -# From the start menu, locate the WDK installation programs folder
* -# Open a build window for the build environment that will be used as the default.
* -# Execute <TT>make.cmd build</TT>
* -# Close the build window and open a \b normal command prompt
* -# Verify propper operation by repeating step #3
*
* <HR>
* \section usbk_building_make_cmd_usage make.cmd Command Line Usage
*
* \subsection usbk_building_make_cmd_usage_syntax Syntax
* \verbatim make.cmd command[=value] <command-specific-arguments> \endverbatim
*
* \subsection usbk_building_make_cmd_usage_commands Commands
<TABLE>
<TR>
	<TH>Command[=value]</TH>
	<TH>command-specific-arguments</TH>
</TR>
<TR>
	<TD>
		\par BUILD
		Builds all projects defined in \b WDK_SOURCES_LIST for a single environment/architecture combination. 
		See the <B>WDK SETUP</B> and \b BUILD sections in \b make.cfg. 

		If no \b setenv.bat command-specific arguments are specified, 
		\b make.cmd will use the defaults defined by \b WDK_DEF_ENV_OPTIONS.
		See the <B>WDK SETUP</B> section in \b make.cfg.

	</TD>
	<TD>
		For more information, see 
		<A href="http://msdn.microsoft.com/en-us/library/ff554139%28v=vs.85%29.aspx">Using the SetEnv.bat</A>
		\par [fre|chk]
		For release builds use the \c fre, for debug builds use \c chk.<BR>
		NOTE: Debug builds include log messages.

		\par [64|x64]:
		Build architecture:
		- \b x64 = AMD64
		- \b 64  = IA64 (rare)

		\par [WIN7|WLH|WXP|WNET|W2K]
		Specifies the Build environment:
		- WIN7 = Windows 7
		- WLH  = Windows Vista
		- WXP  = Windows XP
		- WNET = Windows Server 2003
		- W2K  = Windows 2000
		  W2K is Only supported with WDK version 6001.18002

		\par [no_oacr]
		Disables OACR (Microsoft Auto Code Review)
		
		<HR>
		\par [sign]
		Sign dll, sys, and exe files with a code signing certificate after compiling.<BR>
		See the \b SIGN section in \b make.cfg. 
	</TD>
</TR>
<TR>
	<TD>
		\par DIST
		Build all projects for all environment/architecture combinations defined in \b DIST_BUILD_LIST.
		See the \b DIST section in \b make.cfg. 

		\par dist=finalize
		Used for official release builds.<BR>Build additional components and installers.
		Requires additional configuration.  See \b post_build_libusbK_dll.cfg
	</TD>
	<TD>
		\par [fre|chk]
		For release builds use the \c fre, for debug builds use \c chk.<BR>
		NOTE: chk builds include debug log messages.

		\par [sign]
		Sign dll, sys, and exe files with a code signing certificate after compiling.<BR>
		See the \b SIGN section in \b make.cfg. 
	</TD>
</TR>
<TR>
	<TD>
		\par CLEAN
		Cleans the source and output directories.
		See the \b CLEAN section in \b make.cfg

		\par clean=bin
		Removes temporary files and directories from the output directory.
		See \b CLEAN_BIN_EXP in \b make.cfg.

		\par clean=src
		Removes temporary files and directories from the source directory.
		See \b CLEAN_SRC_EXP in \b make.cfg.

		\par clean=full
		Cleans the source directory.  Removes the output directory entirely.

	</TD>
	<TD>&nbsp;</TD>
</TR>
<TR>
	<TD>
		\par version=package;inc
		Increment the package \b nano version number.

		\par version=package;dec
		Decrement the package \b nano version number.

		\par version=[package|project name]; [inc|dec|set]; [major|macro|minor|nano]; [set value];
		Full package/project version control

	</TD>
	<TD>&nbsp;</TD>
</TR>
<TR>
	<TD>
		\par ZIP
		Create a combined binary and source package.

		\par zip=bin
		Create a binary zip package from the output directory.

		\par zip=src
		Create a source zip package from the source directory.
	</TD>
	<TD>&nbsp;</TD>
</TR>
<TR>
	<TD>
		\par FORMATCODE
		Format source code. (Uses Astyle by default)
		See the \b FORMATCODE section in \b make.cfg
	</TD>
	<TD>&nbsp;</TD>
</TR>
</TABLE>
*
* <HR>
* \section usbk_building_make_cmd_usage_examples Usage Examples
*

* \subsection usbk_building_make_cmd_usage_example_build BUILD examples
\verbatim
make.cmd build
make.cmd build chk
make.cmd build sign
make.cmd build wxp chk sign
\endverbatim

* \subsection usbk_building_make_cmd_usage_example_dist DIST examples
\verbatim
make.cmd dist
make.cmd dist chk
make.cmd dist=finalize chk sign
\endverbatim

* \subsection usbk_building_make_cmd_usage_example_clean CLEAN examples
\par CLEAN examples:
\verbatim
make.cmd clean
make.cmd clean=full
\endverbatim

*
* <HR>
* \section usbk_building_make_cmd_config_examples Configuration Examples
*
* \subsection usbk_building_make_cmd_config_example_make_cfg make.cfg example
\par make.cfg Example:
\include make.cfg

* \subsection usbk_building_make_cmd_config_example_make_versions make.versions example
\par make.versions Example:
\include make.versions

*/

//! Building with a <A href="http://msdn.microsoft.com/en-us/windows/hardware/gg487463">Windows Driver Kit</A>.
/*! \page usbk_building_wdk Building with WDK
*/

//! Building with Microsoft Visual Studios 2008/2010/Express Editions.
/*! \page usbk_building_msvc Building with MSVC
*/

//! Where to begin and how to get started writing your new libusbK based application.
/*! \page usbk_usage Using the Library

The libusbK library documentation is divided into the following sections:
- \copybrief genk
  <HR>
- \copybrief usbk
  <HR>
- \copybrief lstk
  <HR>
- \copybrief drvk
  <HR>
- \copybrief ovlk
  <HR>

*/

/*! \page usbk_power_management libusbK Power Management
* libusbK uses the KMDF state machines for power management. Power
* policies are managed through calls to \ref UsbK_SetPowerPolicy.
*
* In order to modify the power behavior of libusbK, default registry
* settings can be modified in the device's INF. These values must be
* written to the device specific location in the registry by adding the
* values in the HW.AddReg section of the INF.
*
* The registry values described in the following list can be specified in
* the device's INF to modify the power behavior.
*
* \sa UsbK_GetPowerPolicy
* \sa UsbK_SetPowerPolicy
*
* \section usbk_system_wake System Wake
* This feature is controlled by the SystemWakeEnabled DWORD registry
* setting. This value value indicates whether or not the device should be
* allowed to wake the system from a low power state.
*
* \code HKR,,SystemWakeEnabled,0x00010001,1 \endcode
*
* A value of zero, or the absence of this value indicates that the device
* is not allowed to wake the system.
*
* To allow a device to wake the system, set SystemWakeEnabled to a nonzero
* value. A check box in the device Properties page is automatically
* enabled so that the user can override the setting.
*
* \note Changing the SystemWakeEnabled setting has no affect on selective
suspend, this registry value only pertains to system suspend.
*
* \section usbk_selective_suspend Selective Suspend
* Selective suspend can be disabled by any of several system or libusbK
* settings. A single setting cannot force libusbK to enable selective
* suspend.
*
* The following power policy settings that are specified in \ref
* UsbK_SetPowerPolicy's PolicyType parameter affect the behavior of
* selective suspend:
* - AUTO_SUSPEND	\n
*   When set to zero, it does not set the device to selective suspend mode.
* - SUSPEND_DELAY	\n
*   Sets the time between when the device becomes idle and
*   when libusbK requests the device to go into selective suspend.
*
* The following list shows how the registry keys affect the selective
* suspend feature:
* - DeviceIdleEnabled
*   - This is a DWORD value. This registry value indicates whether or not the
*     device is capable of being powered down when idle (Selective Suspend).
*   - A value of zero, or the absence of this value indicates that the device
*     does not support being powered down when idle.
*   - A non-zero value indicates that the device supports being powered down
*     when idle.
*   - If DeviceIdleEnabled is not set, the value of the AUTO_SUSPEND power
*     policy setting is ignored.
*   - \code HKR,,DeviceIdleEnabled,0x00010001,1 \endcode	\n
* - DeviceIdleIgnoreWakeEnable
*   - When set to a nonzero value, it suspends the device even if it does not
*     support RemoteWake.
*   - \code HKR,,DeviceIdleIgnoreWakeEnable,0x00010001,1 \endcode	\n
* - UserSetDeviceIdleEnabled
*   - This value is a DWORD value. This registry value indicates whether or
*     not a check box should be enabled in the device Properties page that
*     allows a user to override the idle defaults. When
*     UserSetDeviceIdleEnabled is set to a nonzero value the check box is
*     enabled and the user can disable powering down the device when idle. A
*     value of zero, or the absence of this value indicates that the check box
*     is not enabled.
*   - If the user disables device power savings, the value of the AUTO_SUSPEND
*     power policy setting is ignored.
*   - If the user enables device power savings, then the value of AUTO_SUSPEND
*     is used to determine whether or not to suspend the device when idle.
*   - The UserSetDeviceIdleEnabled is ignored if DeviceIdleEnabled is not set.
*   - \code HKR,,UserSetDeviceIdleEnabled,0x00010001,1 \endcode	\n
* - DefaultIdleState
*   - This is a DWORD value. This registry value sets the default value of the
*     AUTO_SUSPEND power policy setting. This registry key is used to enable
*     or disable selective suspend when a handle is not open to the device.
*   - A value of zero or the absence of this value indicates that by default,
*     the device is not suspended when idle. The device be allowed to suspend
*     when idle only when the AUTO_SUSPEND power policy is enabled.
*   - A non-zero value indicates that by default the device is allowed to be
*     suspended when idle.
*   - This value is ignored if DeviceIdleEnabled is not set.
*   - \code HKR,,DefaultIdleState,0x00010001,1 \endcode	\n
* - DefaultIdleTimeout
*   - This is a DWORD value. This registry value sets the default state of the
*     SUSPEND_DELAY power policy setting.
*   - The value indicates the amount of time in milliseconds to wait before
*     determining that a device is idle.
*   - \code HKR,,DefaultIdleTimeout,0x00010001,100 \endcode	\n
*
* \section usbk_detecting_idle Detecting Idle
* All writes and control transfers force the device into the D0 power
* state and reset the idle timer. The IN endpoint queues are not power
* managed. Read requests wake the device when they are submitted. However,
* a device can become idle while a read request waits.
*
*/

/*! \page usbk_pipe_management libusbK Pipe Policy Management
*
* To enable applications to get and set an endpoint pipe's default policy
* parameters, libusbK.dll exposes the \ref UsbK_GetPipePolicy function to
* retrieve the pipe's default policy. The \ref UsbK_SetPipePolicy function
* allows an application to set the policy parameter to a new value.
*
* libusbK allows you to modify its default behavior by applying policies
* to an endpoint's pipe. By using these policies, you can configure
* libusbK to best match your device to its capabilities. The following
* table provides a list of the pipe policies that are supported by
* libusbK.
*
* \section usbk_pipe_policies Pipe Policies
* \note
* The policies described in the table are valid only for the specified
* endpoints. Setting the policy on other endpoints has no effect on
* libusbK's behavior for read or write requests.
*
* \htmlonly

<table class="doxtable">
	<th>Policy number</th>
	<th>Policy name</th>
	<th>Description</th>
	<th>Endpoint (direction)</th>
	<th align="right">Default</th>

	<tr>
		<td>0x01</td>
		<td>SHORT_PACKET_TERMINATE</td>
		<td>Terminates every write request with a zero-length packet.</td>
		<td>Bulk (OUT)<br/>Interrupt (OUT)</td>
		<td>Off</td>
	</tr>

	<tr>
		<td>0x02</td>
		<td>AUTO_CLEAR_STALL</td>
		<td>Automatically clears a stalled pipe without stopping the data flow.</td>
		<td>Bulk (IN)<br/>Interrupt (IN)</td>
		<td>Off</td>
	</tr>

	<tr>
		<td>0x03</td>
		<td>PIPE_TRANSFER_TIMEOUT</td>
		<td>Waits for a time-out interval before canceling the request.</td>
		<td>Bulk (IN)<br/>Bulk (OUT)<br/>Interrupt (IN)<br/>Interrupt (OUT)</td>
		<td>5 seconds for control; 0 for others</td>
	</tr>

	<tr>
		<td>0x04</td>
		<td>IGNORE_SHORT_PACKETS</td>
		<td>Completes a read request based on the number of bytes read.</td>
		<td>Bulk (IN)<br/>Interrupt (IN)</td>
		<td>Off</td>
	</tr>

	<tr>
		<td>0x05</td>
		<td>ALLOW_PARTIAL_READS</td>
		<td>Allows read requests from a device that returns more data than requested by the caller.</td>
		<td>Bulk (IN)<br/>Interrupt (IN)</td>
		<td>On</td>
	</tr>

	<tr>
		<td>0x06</td>
		<td>AUTO_FLUSH</td>
		<td>Saves the excess data from the read request and adds it to the next read request or discards the excess data. </td>
		<td>Bulk (IN)<br/>Interrupt (IN)</td>
		<td>Off</td>
	</tr>

	<tr>
		<td>0x07</td>
		<td>RAW_IO</td>
		<td>Bypasses queuing and error handling to boost performance for multiple read requests. </td>
		<td>Bulk (IN)<br/>Interrupt (IN)</td>
		<td>Off</td>
	</tr>

	<tr>
		<td>0x08</td>
		<td>MAXIMUM_TRANSFER_SIZE</td>
		<td>Gets the maximum size of a USB transfer supported by libusbK. This is a read-only policy that can be retrieved by calling WinUsb_GetPipePolicy. </td>
		<td>Bulk (IN)<br/>Bulk (OUT)<br/>Interrupt (IN)<br/>Interrupt (OUT)</td>
		<td>&nbsp;</td>
	</tr>

	<tr>
		<td>0x09</td>
		<td>RESET_PIPE_ON_RESUME</td>
		<td>Resets the endpoint's pipe after resuming from suspend before accepting new requests. </td>
		<td>Bulk (IN)<br/>Bulk (OUT)<br/>Interrupt (IN)<br/>Interrupt (OUT)</td>
		<td>Off</td>
	</tr>

</table>

* \endhtmlonly
* \section usbk_pipe_policies_behavior Behavior and Best Practices
* \note
* The following table identifies best practices for how to use each of the pipe policies and describes the resulting behavior when the policy is enabled.
*
* \htmlonly

<table class="doxtable">
    <tr>
        <th>
            Policy
        </th>
        <th>
            Enable if...
        </th>
        <th>
            Behavior
        </th>
    </tr>
    <tr>
        <td>
            SHORT_PACKET_TERMINATE
        </td>
        <td>
            The device requires the OUT transfers to be terminated with a zero-length packet.
            Most devices do not have this requirement.
        </td>
        <td>
            If enabled (policy parameter value is TRUE or nonzero), every write request is followed
            by a zero-length packet to the endpoint's pipe.
            <br />
            After sending all of the requested data to the host controller, libusbK sends a
            write request with a zero-length packet and then completes the request that was
            created by <b>UsbK_WritePipe</b>.
        </td>
    </tr>
    <tr>
        <td>
            AUTO_CLEAR_STALL
        </td>
        <td>
            You do not want the failed transfers to leave the endpoint in a stalled state. This
            policy is useful only when you have multiple pending read requests to the endpoint
            when RAW_IO is disabled.
        </td>
        <td>
            <ul>
                <li>If enabled (policy parameter value is TRUE or nonzero), a stall condition is cleared
                    automatically. This policy parameter does not affect control pipes.
                    <br />
                    When a read request fails and the host controller returns a status other than STATUS_CANCELLED
                    or STATUS_DEVICE_NOT_CONNECTED, libusbK resets the pipe before completing the failed
                    request. Resetting the pipe clears the stall condition without interrupting the
                    data flow. Data continues to flow in the endpoints as long as new transfers keep
                    arriving from the device. A new transfer can include one that was in the queue when
                    the stall occurred.
                    <br />
                    Enabling this policy does not significantly impact performance. </li>
                <li>If disabled (policy parameter value is FALSE or zero), all transfers that arrive
                    to the endpoint after the stalled transfer fail until the caller manually resets
                    the endpoint's pipe by calling <b>UsbK_ResetPipe</b>. </li>
            </ul>
        </td>
    </tr>
    <tr>
        <td>
            PIPE_TRANSFER_TIMEOUT
        </td>
        <td>
            You expect transfers to an endpoint to complete within a specific time.
        </td>
        <td>
            <ul>
                <li>If set to zero (default), transfers will not time out because the host controller
                    will not cancel the transfer. In this case, the transfer waits indefinitely until
                    it is manually canceled or the transfer completes normally. </li>
                <li>If set to a nonzero value (time-out interval), the host controller starts a timer
                    when it receives the transfer request. When the timer exceeds the set time-out interval,
                    the request is canceled. </li>
                <li>A minor performance penalty will occur due to timer management. </li>
            </ul>
            <b>Requests</b> do not time out while waiting in a libusbK queue.
            <br />
            In Windows Vista, for all transfers (except transfers with RAW_IO enabled), libusbK
            queues the request until all previous transfers on the destination endpoint have
            been completed. The host controller does not include the queuing time in the calculation
            of the time-out interval.
            <br />
            With RAW_IO enabled, libusbK does not queue the request. Instead, it passes the
            request directly to the USB stack, whether or not the USB stack is busy processing
            previous transfers. If the USB stack is busy, it can delay processing the new request.
            Note that this can cause a time-out.
        </td>
    </tr>
    <tr>
        <td>
            IGNORE_SHORT_PACKETS
        </td>
        <td>
            RAW_IO is disabled and you do not want short packets to complete the read requests.
        </td>
        <td>
            <ul>
                <li>If enabled (policy parameter value is TRUE or nonzero), the host controller will
                    not complete a read operation immediately after it receives a short packet. Instead,
                    it completes the operation only if:
                    <ul>
                        <li>An error occurs.</li>
                        <li>The request is canceled.</li>
                        <li>All the requested bytes have been received.</li>
                    </ul>
                </li>
                <li>If disabled (policy parameter value is FALSE or zero), the host controller completes
                    a read operation after it has read the specified number of bytes or has received
                    a short packet. </li>
            </ul>
        </td>
    </tr>
    <tr>
        <td>
            ALLOW_PARTIAL_READS
        </td>
        <td>
            The device can send more data than requested. This is possible if the size of your
            request buffer is a multiple of the maximum endpoint packet size.
            <br />
            Use if your application wants to read a few bytes to determine how many total bytes
            to read.
        </td>
        <td>
            <ul>
                <li>If disabled (policy parameter value is FALSE or zero) and the device returns more
                    data than was requested, libusbK completes the request with an error. </li>
                <li>If enabled (policy parameter value is TRUE or nonzero) and the device returns more
                    data than was requested, libusbK can (depending on AUTO_FLUSH settings) add the
                    excess data from the read request to the beginning of the next read request or discard
                    the excess data. </li>
                <li>If enabled, libusbK immediately completes read requests for zero bytes successfully
                    and will not send the requests down the stack. </li>
            </ul>
        </td>
    </tr>
    <tr>
        <td>
            AUTO_FLUSH
        </td>
        <td>
            ALLOW_PARTIAL _READS policy is enabled.
            <br />
            The device can send more data than was requested, and your application does not
            require any additional data. This is possible if the size of your request buffer
            is a multiple of the maximum endpoint packet size.
        </td>
        <td>
            AUTO_FLUSH defines libusbK's behavior when ALLOW_PARTIAL_READS is enabled. If ALLOW_PARTIAL_READS
            is disabled, the AUTO_FLUSH value is ignored by libusbK.
            <br />
            libusbK can either discard the remaining data or send it with the caller's next
            read request.
            <ul>
                <li>If enabled (policy parameter value is TRUE or nonzero), libusbK discards the extra
                    bytes without any error code. </li>
                <li>If disabled (policy parameter value is FALSE or zero), libusbK saves the extra bytes,
                    adds them to the beginning of the caller's next read request, and then sends the
                    data to the caller in the next read operation. </li>
            </ul>
        </td>
    </tr>
    <tr>
        <td>
            RAW_IO
        </td>
        <td>
            Performance is a priority and the application submits simultaneous read requests
            to the same endpoint.
            <br />
            RAW_IO imposes certain restrictions on the buffer that is passed by the caller in
            <b>UsbK_ReadPipe</b>:
            <ul>
                <li>The buffer length must be a multiple of the maximum endpoint packet size. </li>
                <li>The length must be less than or equal to the value of MAXIMUM_TRANSFER_SIZE retrieved
                    by <b>UsbK_GetPipePolicy</b>. </li>
            </ul>
        </td>
        <td>
            If enabled, transfers bypass queuing and error handling to boost performance for
            multiple read requests. libusbK handles read requests as follows:
            <ul>
                <li>A request that is not a multiple of the maximum endpoint packet size fails.</li>
                <li>A request that is greater than the maximum transfer size supported by libusbK fails.</li>
                <li>All well-formed requests are immediately sent down to the USB core stack to be scheduled
                    in the host controller.</li>
            </ul>
            Enabling this setting significantly improves the performance of multiple read requests
            by reducing the delay between the last packet of one transfer and the first packet
            of the next transfer.
        </td>
    </tr>
    <tr>
        <td>
            RESET_PIPE_ON_RESUME
        </td>
        <td>
            The device does not preserve its data toggle state across suspend.
        </td>
        <td>
            On resume from suspend, libusbK resets the endpoint before it allows the caller
            to send new requests to the endpoint.
        </td>
    </tr>
</table>

* \endhtmlonly
*/