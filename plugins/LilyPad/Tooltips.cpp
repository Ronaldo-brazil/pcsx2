/*  LilyPad - Pad plugin for PS2 Emulator
 *  Copyright (C) 2016  PCSX2 Dev Team/ChickenLiver
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the
 *  terms of the GNU Lesser General Public License as published by the Free
 *  Software Found- ation, either version 3 of the License, or (at your option)
 *  any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with PCSX2.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Global.h"
#include "resource.h"

LPWSTR dialog_message(int ID, bool *updateText)
{
    if (updateText)
        *updateText = true;
    switch (ID) {
        // General tab
        case IDC_M_WM:
        case IDC_M_RAW:
        case IDC_M_DI:
            return L"Enables mouse inputs to be used as pad controls.\n\n"
                   L"The mouse needs to be in focus to be used for playing. By default this is not the case as the \"Start without mouse focus\" checkbox is enabled. "
                   L"Either disable this checkbox or enable/disable the mouse while playing by assigning a key to the \"Mouse\" button on the Pad tabs.\n\n"
                   L"Note 1: By default PCSX2 uses a double-click by the left mouse button to toggle fullscreen mode, this makes the left mouse button unusable as an input."
                   L"To disable this option in PCSX2 go to Config > Emulation Settings > GS Window tab, and disable the \"Double-click toggles fullscreen mode\" checkbox.\n\n"
                   L"Note 2: This does not enable the mouse to function as an in-game mouse in PS2 games that support a USB mouse or lightgun."
                   L"This requires a USB plugin, while LilyPad is a PAD plugin(PAD means it emulates devices that are to be plugged into the PlayStation controller port that connects the DualShock 2 controller).";
        case IDC_MOUSE_UNFOCUS:
            return L"Starts the emulation without the mouse being in focus by the application.\n\n"
                   L"Without mouse focus, the mouse can still be used outside of the emulation.\nWith the mouse in focus it can only be used as an input for the emulator.";
        case IDC_MULTIPLE_BINDING:
            return L"Allows binding multiple PS2 controls to one PC control, and binding conflicting controls on opposing ports and/or slots.\n\n"
                   L"Also enables swapping different kinds of pad types(for example, between DS2 and Guitar) when right-clicking in the pad list.";
        case IDC_PAD_LIST:
            return L"Left-click on one of the available pads to enable the pad specific options on the right."
                   L"These options include being able to select the pad type(DS2, Guitar, etc.) and enabling automatic analog mode for PS1 emulation.\n\n"
                   L"Right-click to show a pop-up menu that allows for swapping all the settings and bindings, or just the bindings of individual pad types,"
                   L"between the selected pad and one of other active pads, and clearing all the settings and bindings from the selected pad or just the bindings from a selected pad type.\n\n"
                   L"Note: To allow swapping different kinds of pad types(like DS2 to Guitar), the \"Allow binding multiple PS2 Controls...\" option needs to be enabled as well.";
        case IDC_ANALOG_START1:
            return L"Automatically switch a pad from digital mode to analog mode whenever a pad is set to digital mode, if the pad's mode is not locked."
                   L"This removes the need for manually enabling analog mode with a press of the analog button for games that support, but do not automatically enable analog mode.\n\n"
                   L"Note 1: Analog mode enables the analog sticks to function on a DualShock controller, while in digital mode it behaves as an original PlayStation controller.\n\n"
                   L"Note 2: If analog mode is enabled in a game that does not support it, a game might not recognise a controller is connected.";
        case ID_TEST:
            return L"Displays a continuously updated list of the state of all objects on the selected device.\n\n"
                   L"Use this option to check if all the inputs on a controller function properly.";
        // Pad tabs
        case ID_MOUSE:
            return L"Bind a key that releases or captures the mouse.\n\n"
                   L"Pressing the assigned button when the mouse is in focus, it releases the mouse from use in-game and makes the cursor visible so it can move/resize the emulator window.\n\n"
                   L"Alt-tabbing to another application also makes the cursor visible, but focusing the emulation window hides it again.\n\n"
                   L"Pressing the button when the mouse is out of focus and visible, it captures the mouse so that it can be used as a controller again.\n\n"
                   L"Note 1: Though the binding appears on the page of a specific pad, pressing the button affects all mice.\n\n"
                   L"Note 2: By default PCSX2 uses a double-click by the left mouse button to toggle fullscreen mode, this makes the left mouse button unusable as an input."
                   L"To disable this option in PCSX2 go to Config > Emulation Settings > GS Window tab, and disable the \"Double-click toggles fullscreen mode\" checkbox.";
        case ID_ANALOG:
            return L"Bind a keys that switches the pad from digital mode to analog mode and vice versa.\n\n"
                   L"This option is useful when analog mode is enabled in a game that does not support it, as this causes the game to not recognise any input or to not even detect a controller.\n\n"
                   L"This option can also be used to enable analog mode in games that support, but do not automatically enable analog mode.\n\n"
                   L"Note: Analog mode enables the analog sticks to function on a DualShock controller, while in digital mode it behaves as an original PlayStation controller.\n\n";
        case ID_IGNORE:
            return L"Blocks the assigned keyboard button and does not pass it on to PCSX2. It currently cannot block the windows key (for unknown reasons).\n\n"
                   L"Ignored keys are listed with pad 1's bindings. You do not have to configure ignored keys again when you change the keyboard input mode.";
        case ID_LOCK_ALL_INPUT:
            return L"Locks the current state of the pad. Any further input is handled normally, but the initial pad state is the locked state instead of a state with no buttons pressed. "
                   L"Pressing it again releases the old pad state, if the old pad state had any keys pressed. Otherwise, it's released automatically.";
        case ID_LOCK_DIRECTION:
            return L"Locks the current state of the d-pad and analog sticks. Pressing this when all input is locked unlocks only the pad and sticks."
                   L"Pressing it again will lock them again, keeping the buttons locked.";
        case ID_LOCK_BUTTONS:
            return L"Locks the current state of the buttons. Pressing this when all input is locked unlocks only the buttons. "
                   L"Pressing it again will lock them again, keeping the d-pad and analog sticks locked.";
        case IDC_TURBO:
            return L"Automatically presses/releases the input every other time the button is polled.";
        case IDC_FLIP:
            return L"Inverts a button or axis, making down up and up down.";
        case IDC_SLIDER_DEADZONE:
            return L"Decreases or increases the range of an input where no input is recognised.\n\n"
                   L"Increasing the dead zone requires the input to be pressed harder or moved more before it is applied, decreasing it makes it recognise a softer press or a shorter movement.";
        case IDC_SLIDER_SENSITIVITY:
            return L"Sets how hard an axis or button is pressed.\n\n"
                   L"Note 1: What the default sensitivity value of \"1.00\" means depends on the device itself. The default is high enough that relative axes (which are primarily used by mice) are generally either considered fully up or down."
                   L"For absolute axes (and force feedback devices), which are used by most game devices, a value of 1.0 should map the device's extreme values to the extreme values of a stick/pad.\n\n"
                   L"Note 2: Setting the sensitivity of PC button bindings only really has an effect for PS2 analog sticks or when playing a game with full DS2 pressure sensitivity support.";
        default:
            if (updateText)
                *updateText = false;
            return L"";
    }
}
