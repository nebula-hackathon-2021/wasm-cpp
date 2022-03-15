package main


import (
	"fmt"
	"net/http"
	"strings"
	"github.com/gin-gonic/gin"
)

var webhookUrl = "https://open.feishu.cn/open-apis/bot/v2/hook/991bf1c0-32de-4d52-a3bd-49fa008bc0d5"

func sendMsg(msg string) {
	// json
	contentType := "application/json"
	// data
	sendData := `{
		"msg_type": "text",
		"content": {"text": "` + "NebulaGraphBot:" + msg + `"}
	}`
	// request
	result, err := http.Post(webhookUrl, contentType, strings.NewReader(sendData))
	if err != nil {
		fmt.Printf("post failed, err:%v\n", err)
		return
	}
	defer result.Body.Close()

}


func main() {
	r := gin.Default()
	r.GET("/:msg", func(c *gin.Context) {
		msg := c.Param("msg")
		sendMsg(msg)
		c.JSON(200, gin.H{
		})
	})
	r.Run(":8888") // listen and serve on 0.0.0.0:8080 (for windows "localhost:8080")
}

