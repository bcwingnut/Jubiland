# Jubiland 😇

*Jubiland*由jubilant（快乐）和land（地区）组成，中文可译为乐土。*Jubiland*是一个基于Unix/Linux系统的大型多人在线角色扮演游戏（MMORPG），题材为魔幻。玩家可以扮演三种不同的角色相互合作以杀死地图上的怪物并提升等级。*Jubiland*为终端游戏，人物、怪物、技能等均使用emoji表示，因此客户端需要运行在支持显示emoji的终端上。本作品的各项参数如下表：

| **开发平台** | Ubuntu 18.04.1   LTS（socket部分）   macOS 10.14（其余部分） | **开发工具** | CLion   2018.2.4   Visual   Studio Code 1.28.1 |
| ------------ | ------------------------------------------------------------ | ------------ | ---------------------------------------------- |
| **运行平台** | 服务器：Unix/Linux   客户端：Unix/Linux（需要终端emoji支持） | **开发语言** | C99   Protocol Buffers Version 2               |
| **环境依赖** | protobuf-c、ncurses（仅客户端）                              |              |                                                |

## 游戏设定

### 世界

*Jubiland*的世界包含一块完整的地图大小为1024*1024，世界中的单位包括玩家控制的**角色**和电脑控制的**怪物**。

### 角色

*Jubiland*中角色的职业包括**战士**（Warrior）、**法师**（Mage）和**牧师**（Priest）三种，每个职业有一个**普通攻击**技能和一个**特殊技能**。战士的定位是“肉盾”，生命值比其他两个职业高，并且普通攻击造成较高伤害。法师是主要的伤害输出者，他可以远程施放火球术。牧师是支援型角色，可以对受伤的其他角色进行治疗，甚至可以复活其他角色。角色的各个属性定义如下表：

| **英文名称** | **中文名称** | **说明**                                           |
| ------------ | ------------ | -------------------------------------------------- |
| **level**    | 等级         | 初始为1，经验值到达当前等级升级所需经验之后自动加1 |
| **class**    | 职业         | 战士、法师和牧师中的一种                           |
| **exp**      | 经验值       | 杀死怪物后获得，用于提升等级                       |
| **hp**       | 生命值       | 受到攻击/治疗时减少/增加，为0时角色阵亡            |
| **mp**       | 法力值       | 施放特殊技能时消耗                                 |
| **ad**       | 攻击伤害     | 角色施放技能时造成伤害或治疗量的基数               |

​       角色不同的技能有不同的系数，特殊技能都会消耗一定法力值，法力值不足时无法释放技能。每个技能施放后有一定的冷却时间，在冷却时间结束前无法再次释放该技能。角色施放技能时造成的伤害或治疗量的计算方法如下：

![img](https://ws3.sinaimg.cn/large/006tNbRwly1fwpcil8c5hj303y00l3ya.jpg)

| **名称**   | **职业**  | **类别** | **说明**                             |
| ---------- | --------- | -------- | ------------------------------------ |
| **劈砍**   | 战士      | 普通攻击 | 用剑砍伤对手，造成中等伤害           |
| **重伤**   | 战士      | 特殊技能 | 全力一击，造成大量伤害，冷却时间较长 |
| **拳击**   | 法师/牧师 | 普通攻击 | 万不得已时使用的技能，造成少量伤害   |
| **火球术** | 法师      | 特殊技能 | 从远处召唤火球对敌方单位造成大量伤害 |
| **治疗术** | 牧师      | 特殊技能 | 从远处祈祷，为友方角色回复大量生命值 |

### 怪物

*Jubiland*的怪物数量是固定的1000个，怪物的状态分为**游荡**、**战斗**和**阵亡**。游荡状态是怪物的默认状态，怪物在该状态下会随机地走动。当怪物被攻击时，会将攻击者加入**威胁列表**中，并进入战斗状态。战斗状态下，怪物会攻击威胁列表中最近的对象。如果一段时间没有受到攻击，会自动回到游荡状态。怪物的生命值为0时死亡，为攻击者增加经验值。怪物死亡一段时间后会复活，进入游荡状态，进入下一个循环。

### 地形

*Jubiland*的地形分为草地、山脉、水域、玫瑰、郁金香、树、帐篷和小岛。角色仅可以通过草地、玫瑰花丛和郁金香花丛，角色进入玫瑰时恢复HP，进入郁金香时恢复MP。其他地形仅作为阻挡和装饰。

## 游戏流程

玩家进入游戏后首先进入职业选择界面，输入上下方向键可以切换职业，输入回车键即可选定职业并进入昵称输入界面。

![image-20181029200348636](https://ws3.sinaimg.cn/large/006tNbRwly1fwpcj1m10ij30io0c00u1.jpg)

玩家在昵称输入界面输入自己的昵称（6～15个英文单词或数字、不能与在线玩家的重复），输入回车键提交昵称。如果服务器响应，则进入游戏界面。

![image-20181029200403385](https://ws2.sinaimg.cn/large/006tNbRwly1fwpcj9ix1nj30lk0duq3x.jpg)

游戏界面上方显示玩家角色状态，中部显示图形，下方显示技能栏。玩家控制的角色始终显示在屏幕中央，使用“王子”emoji表示，其他玩家使用“男孩”emoji表示，不同的怪物、地形也分别用不同的颜色和emoji表示。玩家可以使用方向键或wasd键进行移动，输入TAB键选择目标，输入数字键对目标使用对应的技能。

![img](https://ws1.sinaimg.cn/large/006tNbRwly1fwpcd9ojt2j30wk0ky40c.jpg)

玩家阵亡后进入鬼魂状态，无法移动或攻击，只能被牧师的治疗术（下图中2号技能）复活。

![img](https://ws3.sinaimg.cn/large/006tNbRwly1fwpcd8vyigj30wk0ky76o.jpg)