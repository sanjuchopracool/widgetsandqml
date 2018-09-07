import QtQuick 2.1
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3

Item {
    id: rectangle
    implicitWidth: columnLayout.implicitWidth
    signal widthChanged(int width)
    anchors.fill: parent

    Rectangle {
        id: otherRect
        color: "red"
        anchors.top : parent.top
        width: 200
        height: parent.height

        onXChanged: {
            rectangle.widthChanged(x+width)
        }

        state: "hide"

        function toggleState() {
            otherRect.state = otherRect.state === "show" ? "hide" : "show";
        }

        states: [
            State {
                name: 'hide'

                AnchorChanges {
                    target: otherRect
                    anchors.left: undefined
                    anchors.right: buttonBar.right
                }
            },

            State {
                name: 'show'

                AnchorChanges {
                    target: otherRect
                    anchors.left: buttonBar.right
                    anchors.right: undefined
                }
            }
        ]

        transitions: [
            Transition {
                AnchorAnimation {
                    duration: 200
                }
            }
        ]
    }

    Page {
        id : buttonBar

        height: parent.height

        implicitWidth: columnLayout.implicitWidth
        implicitHeight: columnLayout.implicitHeight

        ColumnLayout {
            id : columnLayout

            VerticalButton {
                id : portSettingButton
                checkable: true
                text: "Port Setting"

                onClicked: {
                    otherRect.toggleState()
                }
            }
        }
    }
}
