/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2019 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    GUIParam_PopupMenu.h
/// @author  Daniel Krajzewicz
/// @date    Mai 2003
/// @version $Id$
///
// A popup-menu for dynamic patameter table entries
/****************************************************************************/
#ifndef GUIParam_PopupMenu_h
#define GUIParam_PopupMenu_h


// ===========================================================================
// included modules
// ===========================================================================
#include <string>

#include <config.h>

#include <fx.h>
#include <utils/common/ValueSource.h>


// ===========================================================================
// class definitions
// ===========================================================================
class GUIGlObject;
class GUIMainWindow;
class GUIParameterTableWindow;


// ===========================================================================
// class declarataions
// ===========================================================================
/**
 * @class GUIParam_PopupMenuInterface
 * @brief A popup-menu for dynamic patameter table entries
 *
 */
class GUIParam_PopupMenuInterface : public FXMenuPane {
    FXDECLARE(GUIParam_PopupMenuInterface)
public:
    /** @brief Constructor
     *
     * @param[in] app The main application window
     * @param[in] parentWindow The parent window (the table the popup belongs to)
     * @param[in] o The object represented by the table
     * @param[in] varName The name of the value
     * @param[in] src The value source
     */
    GUIParam_PopupMenuInterface(GUIMainWindow& app,
                                GUIParameterTableWindow& parentWindow,
                                GUIGlObject& o, const std::string& varName,
                                ValueSource<double>* src);


    /// @brief Destructor
    ~GUIParam_PopupMenuInterface();


    /// @name FOX-callbacks
    /// @{

    /** @brief Called when a tracker for the value shall be opened
     *
     * Builds a new GUIParameterTracker adding the stored value to it.
     * Initialises this tracker, then.
     */
    long onCmdOpenTracker(FXObject*, FXSelector, void*);
    /// @}


protected:
    /// @brief The object the table displays
    GUIGlObject* myObject;

    /// @brief The parameter window this popup was initiated by
    GUIParameterTableWindow* myParentWindow;

    /** @brief The main application window; holder of some needed values */
    GUIMainWindow* myApplication;

    /// @brief The name of the value
    std::string myVarName;

    /// @brief The source of the value
    ValueSource<double>* mySource;

protected:
	FOX_CONSTRUCTOR(GUIParam_PopupMenuInterface)

};


#endif

/****************************************************************************/

