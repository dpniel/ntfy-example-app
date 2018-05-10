import QtQuick 2.4
import QtQuick.Layouts 1.1
import Ubuntu.Components 1.3
import Notify 1.0

MainView {
    id: root
    objectName: 'mainView'
    applicationName: 'ntfy.dpniel'
    automaticOrientation: true

    width: units.gu(45)
    height: units.gu(75)

    Page {
        anchors.fill: parent

        header: PageHeader {
            id: header
            title: i18n.tr('ntfy')
        }

        Column {
            anchors {
                left: parent.left
                top: header.bottom
                right: parent.right
                margins: units.gu(2)
            }

            spacing: units.gu(1)

            TextField {
                id: title
                width: parent.width
                placeholderText: "Title"
            }

            TextField {
                id: message
                width: parent.width
                placeholderText: "Message body"
            }

            Item {
                height: units.gu(5)
                width: parent.width
                Button {
                    anchors.centerIn: parent
                    text: "Send"
                    color: UbuntuColors.green
                    onClicked: Notify.send({
                        "message": "foobar",
                        "notification":{
                            "card": {
                                "summary": title.text,
                                "body": message.text,
                                "popup": true,
                                "persist": true
                            }
                        }
                    });
                }
            }
        }
    }
}
