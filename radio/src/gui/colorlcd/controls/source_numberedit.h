/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "choice.h"
#include "form.h"
#include "numberedit.h"

class TextButton;

class SourceNumberEdit : public Window
{
 public:
  SourceNumberEdit(Window* parent, int32_t vmin, int32_t vmax,
                   std::function<int32_t()> getValue,
                   std::function<void(int32_t)> setValue,
                   int16_t sourceMin,
                   LcdFlags textFlags = 0, int32_t voffset = 0,
                   int32_t vdefault = 0);

  void switchSourceMode();
  void setSuffix(std::string value);

  void setFastStep(int value) { num_field->setFastStep(value); }
  void setAccelFactor(int value) { num_field->setAccelFactor(value); }

  void update();

  static LAYOUT_VAL_SCALED(SRC_BTN_W, 38)

 protected:
  Choice* source_field = nullptr;
  NumberEdit* num_field = nullptr;
  FormField* act_field = nullptr;
  TextButton* m_srcBtn = nullptr;

  int32_t vmin;
  int32_t vmax;
  int16_t sourceMin;
  std::function<int32_t()> getValue;
  std::function<void(int32_t)> setValue;
  LcdFlags textFlags;
  int32_t voffset;

  bool isSource();

  static void value_changed(lv_event_t* e);
};
