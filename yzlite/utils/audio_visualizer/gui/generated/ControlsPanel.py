# -*- coding: UTF-8 -*-
#
# generated by wxGlade 1.0.1 on Wed Apr 28 17:07:33 2021
#

import wx
# begin wxGlade: extracode
import wx.lib.scrolledpanel as scrolled

from yzlite.utils.audio_visualizer.settings import SettingsManager

from ..slider import Slider

# begin wxGlade: dependencies
# end wxGlade

# end wxGlade


class ControlsPanel(scrolled.ScrolledPanel):
    def __init__(self, *args, **kwds):
        # begin wxGlade: ControlsPanel.__init__
        kwds["style"] = kwds.get("style", 0) | wx.TAB_TRAVERSAL
        scrolled.ScrolledPanel.__init__(self, *args, **kwds)

        sizer_3 = wx.BoxSizer(wx.VERTICAL)

        sizer_5 = wx.StaticBoxSizer(wx.StaticBox(
            self, wx.ID_ANY, "General"), wx.VERTICAL)
        sizer_3.Add(sizer_5, 0, wx.ALL | wx.EXPAND, 3)

        grid_sizer_1 = wx.FlexGridSizer(5, 2, 1, 10)
        sizer_5.Add(grid_sizer_1, 1, wx.EXPAND, 0)

        label_31 = wx.StaticText(self, wx.ID_ANY, "Model Path")
        grid_sizer_1.Add(label_31, 0, wx.ALIGN_CENTER_VERTICAL |
                         wx.ALL | wx.EXPAND, 3)

        sizer_10 = wx.BoxSizer(wx.HORIZONTAL)
        grid_sizer_1.Add(sizer_10, 1, wx.EXPAND, 0)

        self.txtCmfModelPath = wx.TextCtrl(self, wx.ID_ANY, "")
        SettingsManager.register_widget('general.model', self.txtCmfModelPath)
        sizer_10.Add(self.txtCmfModelPath, 8, wx.EXPAND, 0)

        self.btnFindCmfModel = wx.Button(
            self, wx.ID_ANY, "...", style=wx.BU_EXACTFIT)
        sizer_10.Add(self.btnFindCmfModel, 0, 0, 0)

        self.btnLoadModel = wx.Button(
            self, wx.ID_ANY, "Reload", style=wx.BU_EXACTFIT)
        sizer_10.Add(self.btnLoadModel, 0, 0, 0)

        label_1 = wx.StaticText(self, wx.ID_ANY, "Audio File")
        grid_sizer_1.Add(label_1, 0, wx.ALIGN_CENTER_VERTICAL |
                         wx.ALL | wx.EXPAND, 3)

        sizer_4 = wx.BoxSizer(wx.HORIZONTAL)
        grid_sizer_1.Add(sizer_4, 1, wx.EXPAND, 0)

        self.txtFilePath = wx.TextCtrl(self, wx.ID_ANY, "")
        SettingsManager.register_widget('general.path', self.txtFilePath)
        sizer_4.Add(self.txtFilePath, 8, wx.EXPAND, 0)

        self.btnFindFile = wx.Button(
            self, wx.ID_ANY, "...", style=wx.BU_EXACTFIT)
        sizer_4.Add(self.btnFindFile, 0, 0, 0)

        self.btnPlay = wx.Button(self, wx.ID_ANY, "Play", style=wx.BU_EXACTFIT)
        sizer_4.Add(self.btnPlay, 0, 0, 0)

        label_2 = wx.StaticText(self, wx.ID_ANY, "Sample Length (ms)")
        grid_sizer_1.Add(label_2, 0, wx.ALL, 3)

        self.txtSampleLength = wx.SpinCtrlDouble(
            self, wx.ID_ANY, initial=0.0, min=0.0, max=100.0, style=wx.SP_ARROW_KEYS | wx.TE_PROCESS_ENTER)
        SettingsManager.register_widget(
            'general.sample_length_ms', self.txtSampleLength)
        self.txtSampleLength.SetIncrement(.10)
        grid_sizer_1.Add(self.txtSampleLength, 1, 0, 0)

        label_3 = wx.StaticText(self, wx.ID_ANY, "Sample Rate (Hz)")
        grid_sizer_1.Add(label_3, 0, wx.ALL, 3)

        self.spin_ctrl_double_7 = wx.SpinCtrlDouble(
            self, wx.ID_ANY, initial=0.0, min=0.0, max=100.0, style=wx.SP_ARROW_KEYS | wx.TE_PROCESS_ENTER)
        SettingsManager.register_widget(
            'general.sample_rate', self.spin_ctrl_double_7)
        self.spin_ctrl_double_7.SetIncrement(1000.0)
        grid_sizer_1.Add(self.spin_ctrl_double_7, 0, 0, 0)

        label_12 = wx.StaticText(self, wx.ID_ANY, "Trim Threshold (dB)")
        grid_sizer_1.Add(label_12, 0, wx.ALIGN_CENTER_VERTICAL | wx.ALL, 3)

        self.spin_ctrl_double_1 = wx.SpinCtrlDouble(
            self, wx.ID_ANY, initial=0.0, min=0.0, max=100.0, style=wx.SP_ARROW_KEYS | wx.TE_PROCESS_ENTER)
        SettingsManager.register_widget(
            'general.trim_threshold_db', self.spin_ctrl_double_1)
        grid_sizer_1.Add(self.spin_ctrl_double_1, 0, 0, 0)

        sizer_1 = wx.StaticBoxSizer(wx.StaticBox(
            self, wx.ID_ANY, "AudioPipeline"), wx.HORIZONTAL)
        sizer_3.Add(sizer_1, 1, wx.EXPAND, 0)

        grid_sizer_4 = wx.FlexGridSizer(3, 2, 0, 0)
        sizer_1.Add(grid_sizer_4, 1, wx.EXPAND, 0)

        label_32 = wx.StaticText(self, wx.ID_ANY, "Loop latency (ms)")
        grid_sizer_4.Add(label_32, 0, 0, 0)

        self.window_20 = Slider(self, wx.ID_ANY, self,
                                'pipeline.period_ms', 'int')
        grid_sizer_4.Add(self.window_20, 1, wx.EXPAND, 0)

        label_33 = wx.StaticText(self, wx.ID_ANY, "Enable")
        grid_sizer_4.Add(label_33, 0, 0, 0)

        self.checkbox_4 = wx.CheckBox(self, wx.ID_ANY, "")
        SettingsManager.register_widget('pipeline.enabled', self.checkbox_4)
        grid_sizer_4.Add(self.checkbox_4, 0, 0, 0)

        label_34 = wx.StaticText(self, wx.ID_ANY, "Step")
        grid_sizer_4.Add(label_34, 0, 0, 0)

        sizer_2 = wx.BoxSizer(wx.HORIZONTAL)
        grid_sizer_4.Add(sizer_2, 1, wx.EXPAND, 0)

        self.btnStepBackward = wx.Button(self, wx.ID_ANY, "<<")
        sizer_2.Add(self.btnStepBackward, 0, 0, 0)

        self.btnStepForward = wx.Button(self, wx.ID_ANY, ">>")
        sizer_2.Add(self.btnStepForward, 0, 0, 0)

        sizer_6 = wx.StaticBoxSizer(wx.StaticBox(
            self, wx.ID_ANY, "Transform"), wx.VERTICAL)
        sizer_3.Add(sizer_6, 0, wx.ALL | wx.EXPAND, 3)

        grid_sizer_2 = wx.FlexGridSizer(7, 2, 1, 10)
        sizer_6.Add(grid_sizer_2, 1, wx.EXPAND, 0)

        label_14 = wx.StaticText(self, wx.ID_ANY, "")
        grid_sizer_2.Add(label_14, 0, 0, 0)

        sizer_8 = wx.BoxSizer(wx.HORIZONTAL)
        grid_sizer_2.Add(sizer_8, 1, wx.EXPAND, 0)

        label_6 = wx.StaticText(self, wx.ID_ANY, "Enabled")
        sizer_8.Add(label_6, 0, wx.ALIGN_CENTER_VERTICAL | wx.RIGHT, 5)

        self.chkEnableTransform = wx.CheckBox(self, wx.ID_ANY, "")
        SettingsManager.register_widget(
            'transform.enabled', self.chkEnableTransform)
        sizer_8.Add(self.chkEnableTransform, 0, wx.EXPAND, 0)

        sizer_8.Add((20, 20), 0, 0, 0)

        label_11 = wx.StaticText(self, wx.ID_ANY, "Auto Play")
        sizer_8.Add(label_11, 0, wx.ALIGN_CENTER_VERTICAL | wx.RIGHT, 5)

        self.chkAutoPlay = wx.CheckBox(self, wx.ID_ANY, "")
        SettingsManager.register_widget('general.auto_play', self.chkAutoPlay)
        sizer_8.Add(self.chkAutoPlay, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        sizer_8.Add((20, 20), 0, 0, 0)

        self.button_1 = wx.Button(self, wx.ID_ANY, "Reset All")
        sizer_8.Add(self.button_1, 0, 0, 0)

        label_4 = wx.StaticText(self, wx.ID_ANY, "Speed")
        grid_sizer_2.Add(label_4, 0, wx.ALIGN_CENTER_VERTICAL | wx.ALL, 3)

        self.window_2 = Slider(self, wx.ID_ANY, self, 'transform.speed_factor')
        grid_sizer_2.Add(self.window_2, 1, wx.EXPAND, 0)

        label_5 = wx.StaticText(self, wx.ID_ANY, "Pitch")
        grid_sizer_2.Add(label_5, 0, wx.ALIGN_CENTER_VERTICAL | wx.ALL, 3)

        self.window_3 = Slider(self, wx.ID_ANY, self,
                               'transform.pitch_factor', 'int')
        grid_sizer_2.Add(self.window_3, 1, wx.EXPAND, 0)

        label_7 = wx.StaticText(self, wx.ID_ANY, "Loudness")
        grid_sizer_2.Add(label_7, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_4 = Slider(self, wx.ID_ANY, self,
                               'transform.loudness_factor')
        grid_sizer_2.Add(self.window_4, 1, wx.EXPAND, 0)

        label_8 = wx.StaticText(self, wx.ID_ANY, "VTLP")
        grid_sizer_2.Add(label_8, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_5 = Slider(self, wx.ID_ANY, self, 'transform.vtlp_factor')
        grid_sizer_2.Add(self.window_5, 1, wx.EXPAND, 0)

        label_9 = wx.StaticText(self, wx.ID_ANY, "Noise Color")
        grid_sizer_2.Add(label_9, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.combo_box_1 = wx.ComboBox(self, wx.ID_ANY, choices=[
                                       "None", "White", "Brown", "Blue", "Pink", "Violet"], style=wx.CB_DROPDOWN | wx.CB_READONLY)
        SettingsManager.register_widget(
            'transform.noise_color', self.combo_box_1)
        grid_sizer_2.Add(self.combo_box_1, 0, wx.EXPAND, 0)

        label_10 = wx.StaticText(self, wx.ID_ANY, "Noise Color Loudness")
        grid_sizer_2.Add(label_10, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_6 = Slider(self, wx.ID_ANY, self,
                               'transform.noise_color_factor')
        grid_sizer_2.Add(self.window_6, 1, wx.EXPAND, 0)

        sizer_7 = wx.StaticBoxSizer(wx.StaticBox(
            self, wx.ID_ANY, "Frontend"), wx.VERTICAL)
        sizer_3.Add(sizer_7, 0, wx.ALL | wx.EXPAND, 3)

        grid_sizer_3 = wx.FlexGridSizer(17, 2, 1, 10)
        sizer_7.Add(grid_sizer_3, 1, wx.EXPAND, 0)

        label_13 = wx.StaticText(self, wx.ID_ANY, "")
        grid_sizer_3.Add(label_13, 0, 0, 0)

        sizer_9 = wx.BoxSizer(wx.HORIZONTAL)
        grid_sizer_3.Add(sizer_9, 1, wx.EXPAND, 0)

        label_15 = wx.StaticText(self, wx.ID_ANY, "Enabled")
        sizer_9.Add(label_15, 0, wx.ALIGN_CENTER_VERTICAL | wx.RIGHT, 5)

        self.chkEnableFrontend = wx.CheckBox(self, wx.ID_ANY, "")
        SettingsManager.register_widget(
            'frontend.enabled', self.chkEnableFrontend)
        sizer_9.Add(self.chkEnableFrontend, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        sizer_9.Add((20, 20), 0, 0, 0)

        self.button_2 = wx.Button(self, wx.ID_ANY, "Reset All")
        sizer_9.Add(self.button_2, 0, 0, 0)

        label_16 = wx.StaticText(self, wx.ID_ANY, "Window Size")
        grid_sizer_3.Add(label_16, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_7 = Slider(self, wx.ID_ANY, self,
                               'frontend.window_size', 'int')
        grid_sizer_3.Add(self.window_7, 1, wx.EXPAND, 0)

        label_17 = wx.StaticText(self, wx.ID_ANY, "Window Step")
        grid_sizer_3.Add(label_17, 0, 0, 0)

        self.window_8 = Slider(self, wx.ID_ANY, self,
                               'frontend.window_step', 'int')
        grid_sizer_3.Add(self.window_8, 1, wx.EXPAND, 0)

        label_18 = wx.StaticText(self, wx.ID_ANY, "Num Channels")
        grid_sizer_3.Add(label_18, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_9 = Slider(self, wx.ID_ANY, self,
                               'frontend.num_channels', 'int')
        grid_sizer_3.Add(self.window_9, 1, wx.EXPAND, 0)

        label_19 = wx.StaticText(self, wx.ID_ANY, "Upper Band Limit")
        grid_sizer_3.Add(label_19, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_10 = Slider(self, wx.ID_ANY, self,
                                'frontend.upper_band_limit', 'int')
        grid_sizer_3.Add(self.window_10, 1, wx.EXPAND, 0)

        label_20 = wx.StaticText(self, wx.ID_ANY, "Lower Band Limit")
        grid_sizer_3.Add(label_20, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_11 = Slider(self, wx.ID_ANY, self,
                                'frontend.lower_band_limit', 'int')
        grid_sizer_3.Add(self.window_11, 1, wx.EXPAND, 0)

        label_39 = wx.StaticText(self, wx.ID_ANY, "Enable Noise Deduction")
        grid_sizer_3.Add(label_39, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.checkbox_5 = wx.CheckBox(self, wx.ID_ANY, "")
        SettingsManager.register_widget(
            'frontend.enable_noise_reduction', self.checkbox_5)
        grid_sizer_3.Add(self.checkbox_5, 0, 0, 0)

        label_21 = wx.StaticText(self, wx.ID_ANY, "Smoothing Bits")
        grid_sizer_3.Add(label_21, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_12 = Slider(self, wx.ID_ANY, self,
                                'frontend.smoothing_bits', 'int')
        grid_sizer_3.Add(self.window_12, 1, wx.EXPAND, 0)

        label_22 = wx.StaticText(self, wx.ID_ANY, "Even Smoothing")
        grid_sizer_3.Add(label_22, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_13 = Slider(self, wx.ID_ANY, self,
                                'frontend.even_smoothing', digits=3)
        grid_sizer_3.Add(self.window_13, 1, wx.EXPAND, 0)

        label_23 = wx.StaticText(self, wx.ID_ANY, "Odd Smoothing")
        grid_sizer_3.Add(label_23, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_14 = Slider(self, wx.ID_ANY, self,
                                'frontend.odd_smoothing', digits=3)
        grid_sizer_3.Add(self.window_14, 1, wx.EXPAND, 0)

        label_24 = wx.StaticText(self, wx.ID_ANY, "Min Signal Remaining")
        grid_sizer_3.Add(label_24, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_15 = Slider(self, wx.ID_ANY, self,
                                'frontend.min_signal_remaining', digits=3)
        grid_sizer_3.Add(self.window_15, 1, wx.EXPAND, 0)

        label_25 = wx.StaticText(self, wx.ID_ANY, "PCAN Enabled")
        grid_sizer_3.Add(label_25, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.checkbox_2 = wx.CheckBox(self, wx.ID_ANY, "")
        SettingsManager.register_widget(
            'frontend.enable_pcan', self.checkbox_2)
        grid_sizer_3.Add(self.checkbox_2, 0, 0, 0)

        label_26 = wx.StaticText(self, wx.ID_ANY, "PCAN Strength")
        grid_sizer_3.Add(label_26, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_16 = Slider(self, wx.ID_ANY, self,
                                'frontend.pcan_strength', digits=3)
        grid_sizer_3.Add(self.window_16, 1, wx.EXPAND, 0)

        label_27 = wx.StaticText(self, wx.ID_ANY, "PCAN Offset")
        grid_sizer_3.Add(label_27, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_17 = Slider(self, wx.ID_ANY, self, 'frontend.pcan_offset')
        grid_sizer_3.Add(self.window_17, 1, wx.EXPAND, 0)

        label_28 = wx.StaticText(self, wx.ID_ANY, "Gain Bits")
        grid_sizer_3.Add(label_28, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_18 = Slider(self, wx.ID_ANY, self,
                                'frontend.gain_bits', 'int')
        grid_sizer_3.Add(self.window_18, 1, wx.EXPAND, 0)

        label_29 = wx.StaticText(self, wx.ID_ANY, "Log Enabled")
        grid_sizer_3.Add(label_29, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.checkbox_3 = wx.CheckBox(self, wx.ID_ANY, "")
        SettingsManager.register_widget('frontend.enable_log', self.checkbox_3)
        grid_sizer_3.Add(self.checkbox_3, 0, 0, 0)

        label_30 = wx.StaticText(self, wx.ID_ANY, "Scale Shift")
        grid_sizer_3.Add(label_30, 0, wx.ALIGN_CENTER_VERTICAL, 0)

        self.window_19 = Slider(self, wx.ID_ANY, self,
                                'frontend.scale_shift', 'int')
        grid_sizer_3.Add(self.window_19, 1, wx.EXPAND, 0)

        grid_sizer_3.AddGrowableCol(1)

        grid_sizer_2.AddGrowableCol(1)

        grid_sizer_4.AddGrowableCol(1)

        grid_sizer_1.AddGrowableCol(1)

        self.SetSizer(sizer_3)

        self.Layout()

        self.Bind(wx.EVT_TEXT_ENTER, self.on_txt_model_file_path,
                  self.txtCmfModelPath)
        self.Bind(wx.EVT_BUTTON, self.on_btn_find_model_file,
                  self.btnFindCmfModel)
        self.Bind(wx.EVT_BUTTON, self.on_btn_load_model, self.btnLoadModel)
        self.Bind(wx.EVT_TEXT_ENTER,
                  self.on_txt_audio_file_path, self.txtFilePath)
        self.Bind(wx.EVT_BUTTON, self.on_btn_find_audio_file, self.btnFindFile)
        self.Bind(wx.EVT_BUTTON, self.on_btn_play_audio, self.btnPlay)
        self.Bind(wx.EVT_SPINCTRLDOUBLE,
                  self.on_setting_updated, self.txtSampleLength)
        self.Bind(wx.EVT_TEXT_ENTER, self.on_setting_updated,
                  self.txtSampleLength)
        self.Bind(wx.EVT_SPINCTRLDOUBLE, self.on_setting_updated,
                  self.spin_ctrl_double_7)
        self.Bind(wx.EVT_TEXT_ENTER, self.on_setting_updated,
                  self.spin_ctrl_double_7)
        self.Bind(wx.EVT_SPINCTRLDOUBLE, self.on_setting_updated,
                  self.spin_ctrl_double_1)
        self.Bind(wx.EVT_TEXT_ENTER, self.on_setting_updated,
                  self.spin_ctrl_double_1)
        self.Bind(wx.EVT_CHECKBOX, self.on_setting_updated, self.checkbox_4)
        self.Bind(wx.EVT_BUTTON, self.on_btn_step_backward,
                  self.btnStepBackward)
        self.Bind(wx.EVT_BUTTON, self.on_btn_step_forward, self.btnStepForward)
        self.Bind(wx.EVT_CHECKBOX, self.on_chk_enable_transform,
                  self.chkEnableTransform)
        self.Bind(wx.EVT_CHECKBOX, self.on_chk_auto_play, self.chkAutoPlay)
        self.Bind(wx.EVT_BUTTON, self.on_btn_reset_transform, self.button_1)
        self.Bind(wx.EVT_COMBOBOX, self.on_setting_updated, self.combo_box_1)
        self.Bind(wx.EVT_CHECKBOX, self.on_chk_enable_frontend,
                  self.chkEnableFrontend)
        self.Bind(wx.EVT_BUTTON, self.on_btn_reset_frontend, self.button_2)
        self.Bind(wx.EVT_CHECKBOX, self.on_setting_updated, self.checkbox_5)
        self.Bind(wx.EVT_CHECKBOX, self.on_setting_updated, self.checkbox_2)
        self.Bind(wx.EVT_CHECKBOX, self.on_setting_updated, self.checkbox_3)
        # end wxGlade

    # wxGlade: ControlsPanel.<event_handler>
    def on_txt_model_file_path(self, event):
        print("Event handler 'on_txt_model_file_path' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_btn_find_model_file(self, event):
        print("Event handler 'on_btn_find_model_file' not implemented!")
        event.Skip()

    def on_btn_load_model(self, event):  # wxGlade: ControlsPanel.<event_handler>
        print("Event handler 'on_btn_load_model' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_txt_audio_file_path(self, event):
        print("Event handler 'on_txt_audio_file_path' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_btn_find_audio_file(self, event):
        print("Event handler 'on_btn_find_audio_file' not implemented!")
        event.Skip()

    def on_btn_play_audio(self, event):  # wxGlade: ControlsPanel.<event_handler>
        print("Event handler 'on_btn_play_audio' not implemented!")
        event.Skip()

    def on_setting_updated(self, event):  # wxGlade: ControlsPanel.<event_handler>
        print("Event handler 'on_setting_updated' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_btn_step_backward(self, event):
        print("Event handler 'on_btn_step_backward' not implemented!")
        event.Skip()

    def on_btn_step_forward(self, event):  # wxGlade: ControlsPanel.<event_handler>
        print("Event handler 'on_btn_step_forward' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_chk_enable_transform(self, event):
        print("Event handler 'on_chk_enable_transform' not implemented!")
        event.Skip()

    def on_chk_auto_play(self, event):  # wxGlade: ControlsPanel.<event_handler>
        print("Event handler 'on_chk_auto_play' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_btn_reset_transform(self, event):
        print("Event handler 'on_btn_reset_transform' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_chk_enable_frontend(self, event):
        print("Event handler 'on_chk_enable_frontend' not implemented!")
        event.Skip()

    # wxGlade: ControlsPanel.<event_handler>
    def on_btn_reset_frontend(self, event):
        print("Event handler 'on_btn_reset_frontend' not implemented!")
        event.Skip()

# end of class ControlsPanel
