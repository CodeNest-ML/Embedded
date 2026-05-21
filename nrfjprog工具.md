## 擦除
nrfjprog --eraseall -f NRF52

## 烧录
nrfjprog --program app.hex --verify -f NRF52
其中app.hex是你需要烧录的文件，需要注意的是该文件需要和你的命令行工具在同一目录。

## 复位
nrfjprog --reset -f NRF52