import QtQuick 2.15
import QtQuick.VirtualKeyboard 2.15
import QtQuick.Controls 2.15

Item {
    id: root
    width: 800
    height: 400

    // 输入框
    Rectangle{
        width: parent.width/2 - 10
        height: 100
        x:5
        y:5
        color: "black"  // 背景颜色
        TextInput{
            id: inputtext
            anchors.centerIn: parent  // 居中
            color: "white"
            focus: true
        }
    }

    // 确认键 和 取消键 的信号
    signal qmlCloseSignal()  // 取消键信号
    signal qmlSendSignal(var data)  // 确认键传送数据

    // 确定键
    Rectangle{
        width: parent.width/4 -10
        height: 100
        x: parent.width/2 + 5
        y:5
        color: "#4f5b62"
        radius: 5
        Text {
            id: text_1
            anchors.centerIn: parent
            color: "white"
            text: "确定"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                root.qmlSendSignal(inputtext.text)  // 点击确定, 发送信号  inputtext.text: 输入框的内容
                inputtext.text = ""
            }
        }
    }

    // 取消键
    Rectangle{
        width: parent.width/4 - 10
        height: 100
        x: parent.width*3/4+5
        y: 5
        color: "#4f5b62"
        radius: 5
        Text{
            id: text_2
            anchors.centerIn: parent
            color: "white"
            text: "取消"
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{
                root.qmlCloseSignal()
            }
        }
    }

    // 键盘
    InputPanel{
        id: keyboard_1
        // 可见性
        visible: true
        // 确定键盘宽度
        anchors.left: parent.left
        anchors.right: parent.right
        x: 0
        y: 120
    }
}
