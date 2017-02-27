/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DebugExampleAudioProcessorEditor::DebugExampleAudioProcessorEditor (DebugExampleAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderPanPosition = new Slider ("new slider"));
    sliderPanPosition->setRange (-1, 1, 0);
    sliderPanPosition->setSliderStyle (Slider::Rotary);
    sliderPanPosition->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderPanPosition->addListener (this);

    addAndMakeVisible (buttonPanningAlgorithm = new ToggleButton ("new toggle button"));
    buttonPanningAlgorithm->setButtonText (TRANS("Linear / Constant"));
    buttonPanningAlgorithm->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);//starts timer with interval of 200mS
    //[/Constructor]
}

DebugExampleAudioProcessorEditor::~DebugExampleAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderPanPosition = nullptr;
    buttonPanningAlgorithm = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DebugExampleAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DebugExampleAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderPanPosition->setBounds (24, 32, 176, 120);
    buttonPanningAlgorithm->setBounds (72, 184, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DebugExampleAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderPanPosition)
    {
        //[UserSliderCode_sliderPanPosition] -- add your slider handling code here..
        processor.constantPower = sliderPanPosition->getValue(); // Intentional fault 1
        //processor.panPosition = sliderPanPosition->getValue(); // Intentional bug 1
        //[/UserSliderCode_sliderPanPosition]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void DebugExampleAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == buttonPanningAlgorithm)
    {
        //[UserButtonCode_buttonPanningAlgorithm] -- add your button handler code here..
        processor.panPosition = buttonPanningAlgorithm->getToggleState(); // Intentional bug 2
        //processor.constantPower = buttonPanningAlgorithm->getToggleState();
        //[/UserButtonCode_buttonPanningAlgorithm]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void DebugExampleAudioProcessorEditor::timerCallback()
{
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DebugExampleAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="DebugExampleAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="ceaa68e8ca3b691c" memberName="sliderPanPosition"
          virtualName="" explicitFocusOrder="0" pos="24 32 176 120" min="-1"
          max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="new toggle button" id="b88aa77a47a911c7" memberName="buttonPanningAlgorithm"
                virtualName="" explicitFocusOrder="0" pos="72 184 150 24" buttonText="Linear / Constant"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
