import QtQuick 2.15
import QtQuick.VirtualKeyboard 2.15
import QtQuick.Controls 2.15

Item {
    id: root
    width: 800
    height: 400

    // 输入框
    Rectangle{
        id: rect_1
        width: 800
        height: 100
        color: "black"  // 背景颜色
        TextInput{
            id: text_1
            anchors.centerIn: parent  // 居中
            color: "white"
            focus: true
            onFocusChanged: {
                console.log("text_1 focus changed:", focus)
            }

        }
    }

    // 输入框
    Rectangle{
        id: rect_2
        width: 800
        height: 100
        color: "black"  // 背景颜色
        TextInput{
            id: text_2
            anchors.centerIn: parent  // 居中
            color: "white"
            onFocusChanged: {
                console.log("text_2 focus changed:", focus)
            }
        }
        y: 110
    }
    // 不要使用 这个Button每次点击的时候, 会直接将text_1.foucs, 这样就会导致每次都会将text_1置为输入框
    // Button{
    //     // width: 800
    //     // height: 50
    //     text: "Switch Focus"
    //     focus: false
    //     onClicked: {
    //         // 切换焦点
    //         console.log("Switch button clicked. text_1.focus:", text_1.focus, "text_2.focus:", text_2.focus)
    //         if (text_1.focus) {
    //             console.log("Switching focus to text_2")
    //             text_2.forceActiveFocus()
    //         }else{
    //             console.log("Switching focus to text_1")
    //             text_1.forceActiveFocus()
    //         }
    //     }
    //     y: 220
    // }

    Rectangle {
        width: 400
        height: 50
        color: "lightgrey"
        border.color: "black"
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            text: "switch input"
            color: "black"
            font.pixelSize: 24
            anchors.centerIn: parent  // 将文本居中对齐
        }

        // 鼠标点击事件
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                console.log("Switch button clicked. text_1.focus:", text_1.focus, "text_2.focus:", text_2.focus)
                Qt.callLater(function() {
                    if (text_1.focus) {
                        console.log("Switching focus to text_2")
                        text_2.forceActiveFocus()
                    } else {
                        console.log("Switching focus to text_1")
                        text_1.forceActiveFocus()
                    }
                })
            }
        }
        y: 220
    }

    // 键盘
    InputPanel{
        id: keyboard_1
        // 可见性
        visible: true
        // 确定键盘宽度
        anchors.left: parent.left
        anchors.right: parent.right
        y: 280
    }
}
