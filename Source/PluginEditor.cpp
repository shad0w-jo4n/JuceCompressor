/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginAudioProcessorEditor::PluginAudioProcessorEditor (PluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible (thresholdSlider = new Slider ("Threshold Slider"));
    thresholdSlider->setRange (-20, 0, 0.01);
    thresholdSlider->setSliderStyle (Slider::LinearVertical);
    thresholdSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    thresholdSlider->addListener (this);

    addAndMakeVisible (ratioSlider = new Slider ("Ratio Slider"));
    ratioSlider->setRange (1, 10, 0.01);
    ratioSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    ratioSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    ratioSlider->setColour (Slider::thumbColourId, Colours::white);
    ratioSlider->setColour (Slider::trackColourId, Colours::white);
    ratioSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    ratioSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    ratioSlider->addListener (this);

    addAndMakeVisible (ratioLabel = new Label ("Ratio Label",
                                               TRANS("Ratio")));
    ratioLabel->setFont (Font (16.00f, Font::plain));
    ratioLabel->setJustificationType (Justification::centred);
    ratioLabel->setEditable (false, false, false);
    ratioLabel->setColour (Label::textColourId, Colours::white);
    ratioLabel->setColour (TextEditor::textColourId, Colours::black);
    ratioLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (thresholdLabel = new Label ("Threshold Label",
                                                   TRANS("Threshold")));
    thresholdLabel->setFont (Font (16.00f, Font::plain));
    thresholdLabel->setJustificationType (Justification::centred);
    thresholdLabel->setEditable (false, false, false);
    thresholdLabel->setColour (Label::textColourId, Colours::white);
    thresholdLabel->setColour (TextEditor::textColourId, Colours::black);
    thresholdLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (attackSlider = new Slider ("Attack Slider"));
    attackSlider->setRange (0, 100, 1);
    attackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    attackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackSlider->setColour (Slider::thumbColourId, Colours::white);
    attackSlider->setColour (Slider::trackColourId, Colours::white);
    attackSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    attackSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    attackSlider->addListener (this);

    addAndMakeVisible (attackLabel = new Label ("Attack Label",
                                                TRANS("Attack")));
    attackLabel->setFont (Font (16.00f, Font::plain));
    attackLabel->setJustificationType (Justification::centred);
    attackLabel->setEditable (false, false, false);
    attackLabel->setColour (Label::textColourId, Colours::white);
    attackLabel->setColour (TextEditor::textColourId, Colours::black);
    attackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (releaseSlider = new Slider ("Release Slider"));
    releaseSlider->setRange (0, 1500, 1);
    releaseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    releaseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseSlider->setColour (Slider::thumbColourId, Colours::white);
    releaseSlider->setColour (Slider::trackColourId, Colours::white);
    releaseSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    releaseSlider->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    releaseSlider->addListener (this);

    addAndMakeVisible (releaseLabel = new Label ("Release Label",
                                                 TRANS("Release\n")));
    releaseLabel->setFont (Font (16.00f, Font::plain));
    releaseLabel->setJustificationType (Justification::centred);
    releaseLabel->setEditable (false, false, false);
    releaseLabel->setColour (Label::textColourId, Colours::white);
    releaseLabel->setColour (TextEditor::textColourId, Colours::black);
    releaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    // Add any other settings not offered by GUI editor here, else they'll be deleted
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    // Uncomment to apply custom styling from PluginLookAndFeel
//    LookAndFeel::setDefaultLookAndFeel(&pluginLookAndFeel);

    startTimer (50);
    //[/Constructor]
}

PluginAudioProcessorEditor::~PluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    thresholdSlider = nullptr;
    ratioSlider = nullptr;
    ratioLabel = nullptr;
    thresholdLabel = nullptr;
    attackSlider = nullptr;
    attackLabel = nullptr;
    releaseSlider = nullptr;
    releaseLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    deleteAllChildren();    // Just in case you miss something (maybe unneeded)
    //[/Destructor]
}

//==============================================================================
void PluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff222222));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    thresholdSlider->setBounds (8, 40, 80, 216);
    ratioSlider->setBounds (96, 48, 80, 88);
    ratioLabel->setBounds (96, 16, 80, 24);
    thresholdLabel->setBounds (8, 8, 80, 24);
    attackSlider->setBounds (192, 48, 80, 88);
    attackLabel->setBounds (192, 16, 80, 24);
    releaseSlider->setBounds (288, 48, 80, 88);
    releaseLabel->setBounds (288, 16, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == thresholdSlider)
    {
        //[UserSliderCode_thresholdSlider] -- add your slider handling code here..
        normalizedValue = processor.userParams[processor.threshold].setWithUparam(sliderThatWasMoved->getValue());
        processor.setParameterNotifyingHost(processor.threshold, normalizedValue);
        //[/UserSliderCode_thresholdSlider]
    }
    else if (sliderThatWasMoved == ratioSlider)
    {
        //[UserSliderCode_ratioSlider] -- add your slider handling code here..
        normalizedValue = processor.userParams[processor.ratio].setWithUparam(sliderThatWasMoved->getValue());
        processor.setParameterNotifyingHost(processor.ratio, normalizedValue);
        //[/UserSliderCode_ratioSlider]
    }
    else if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_releaseSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginAudioProcessorEditor::timerCallback() {
    // Set UI values to match any changes made by host automation
    // Timer conflicts cause UI stuttering, this is due to the values not being mapped back

    thresholdSlider ->setValue(processor.userParams[processor.threshold].getUparamVal(), dontSendNotification);
    ratioSlider     ->setValue(processor.userParams[processor.ratio].getUparamVal(), dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="PluginAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff222222"/>
  <SLIDER name="Threshold Slider" id="1e116366caad33a9" memberName="thresholdSlider"
          virtualName="" explicitFocusOrder="0" pos="8 40 80 216" min="-20"
          max="0" int="0.010000000000000000208" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Ratio Slider" id="fa177f4e096ea6ca" memberName="ratioSlider"
          virtualName="" explicitFocusOrder="0" pos="96 48 80 88" thumbcol="ffffffff"
          trackcol="ffffffff" rotarysliderfill="ffffffff" rotaryslideroutline="ffffffff"
          min="1" max="10" int="0.010000000000000000208" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Ratio Label" id="f294c64e2fc7b65a" memberName="ratioLabel"
         virtualName="" explicitFocusOrder="0" pos="96 16 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Ratio" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="16" bold="0" italic="0" justification="36"/>
  <LABEL name="Threshold Label" id="fb70f7ef7b840df7" memberName="thresholdLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Threshold" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="16" bold="0" italic="0" justification="36"/>
  <SLIDER name="Attack Slider" id="fbc71e13665cf008" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="192 48 80 88" thumbcol="ffffffff"
          trackcol="ffffffff" rotarysliderfill="ffffffff" rotaryslideroutline="ffffffff"
          min="0" max="100" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Attack Label" id="7d7c9a4fc245a53" memberName="attackLabel"
         virtualName="" explicitFocusOrder="0" pos="192 16 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Attack" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="16" bold="0" italic="0" justification="36"/>
  <SLIDER name="Release Slider" id="a213a9ca4aa20bd9" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="288 48 80 88" thumbcol="ffffffff"
          trackcol="ffffffff" rotarysliderfill="ffffffff" rotaryslideroutline="ffffffff"
          min="0" max="1500" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Release Label" id="41968c8967492114" memberName="releaseLabel"
         virtualName="" explicitFocusOrder="0" pos="288 16 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Release&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="16" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
