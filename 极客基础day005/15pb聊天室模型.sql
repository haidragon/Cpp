CREATE TABLE `用户表` (
`id` int NOT NULL AUTO_INCREMENT,
`name` varchar NULL,
PRIMARY KEY (`id`) 
);

CREATE TABLE `用户关系表` (
`id` int NOT NULL,
`user1_id` int NULL,
`user2_id` int NULL,
PRIMARY KEY (`id`) 
);

CREATE TABLE `聊天室` (
`id` int NOT NULL,
`roomNumber` int NULL,
`maxCount` int(11) NULL,
`curCount` int(11) NULL,
PRIMARY KEY (`id`) 
);

CREATE TABLE `聊天室用户表` (
`id` int NOT NULL AUTO_INCREMENT,
`user_id` int NULL,
`room_id` int NULL,
PRIMARY KEY (`id`) 
);

CREATE TABLE `消息表` (
`id` int NOT NULL AUTO_INCREMENT,
`sender_id` int NULL COMMENT '哪个用户发的消息',
`recver_id` int NULL DEFAULT 接收者id,
`msgData` text NULL,
PRIMARY KEY (`id`) 
);


ALTER TABLE `用户关系表` ADD CONSTRAINT `fk_用户关系表_用户表_1` FOREIGN KEY (`user1_id`) REFERENCES `用户表` (`id`);
ALTER TABLE `用户关系表` ADD CONSTRAINT `fk_用户关系表_用户表_2` FOREIGN KEY (`user2_id`) REFERENCES `用户表` (`id`);
ALTER TABLE `聊天室用户表` ADD CONSTRAINT `fk_聊天室用户表_用户表_1` FOREIGN KEY (`user_id`) REFERENCES `用户表` (`id`);
ALTER TABLE `聊天室用户表` ADD CONSTRAINT `fk_聊天室用户表_聊天室_1` FOREIGN KEY (`room_id`) REFERENCES `聊天室` (`id`);
ALTER TABLE `消息表` ADD CONSTRAINT `fk_消息表_用户表_1` FOREIGN KEY (`sender_id`) REFERENCES `用户表` (`id`);
ALTER TABLE `消息表` ADD CONSTRAINT `fk_消息表_用户表_2` FOREIGN KEY (`recver_id`) REFERENCES `用户表` (`id`);

