## 擦除
nrfjprog --eraseall -f NRF52

## 烧录
nrfjprog --program app.hex --verify -f NRF52
其中app.hex是你需要烧录的文件，需要注意的是该文件需要和你的命令行工具在同一目录。

## 复位
nrfjprog --reset -f NRF52

## 解锁芯片（如果芯片没有识别出具体型号只是显示NRF52_FAMILY，那很大可能就是芯片出厂被锁了，触发了APPROTECT（读保护））
nrfjprog --recover -f NRF52