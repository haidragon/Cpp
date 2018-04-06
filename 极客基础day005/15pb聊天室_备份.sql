/*
Navicat MySQL Data Transfer

Source Server         : win7_mysql
Source Server Version : 50716
Source Host           : 192.168.40.129:3306
Source Database       : 15pb聊天室

Target Server Type    : MYSQL
Target Server Version : 50716
File Encoding         : 65001

Date: 2018-03-31 09:49:01
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for classroom
-- ----------------------------
DROP TABLE IF EXISTS `classroom`;
CREATE TABLE `classroom` (
  `id` int(11) NOT NULL,
  `name` varchar(255) COLLATE utf8_bin DEFAULT NULL,
  `maxCount` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- ----------------------------
-- Records of classroom
-- ----------------------------
INSERT INTO `classroom` VALUES ('1', '20期', '20');
INSERT INTO `classroom` VALUES ('2', '21期', '30');
INSERT INTO `classroom` VALUES ('3', '22期', '40');
INSERT INTO `classroom` VALUES ('4', '23期', '45');
INSERT INTO `classroom` VALUES ('5', '24期', '50');
INSERT INTO `classroom` VALUES ('6', '25期', '55');
INSERT INTO `classroom` VALUES ('7', '26期', '60');

-- ----------------------------
-- Table structure for 用户表
-- ----------------------------
DROP TABLE IF EXISTS `用户表`;
CREATE TABLE `用户表` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) COLLATE utf8_bin NOT NULL DEFAULT '',
  `height` double NOT NULL DEFAULT '1.6',
  `age` int(11) NOT NULL DEFAULT '18',
  `classroomid` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`),
  KEY `uq_name` (`name`),
  KEY `fk_user_classroom` (`classroomid`),
  CONSTRAINT `fk_user_classroom` FOREIGN KEY (`classroomid`) REFERENCES `classroom` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- ----------------------------
-- Records of 用户表
-- ----------------------------
INSERT INTO `用户表` VALUES ('1', '如花', '2', '12', '2');
INSERT INTO `用户表` VALUES ('2', '小明', '1.5', '11', null);
INSERT INTO `用户表` VALUES ('3', '小红红', '2', '18', '2');
INSERT INTO `用户表` VALUES ('4', '周星驰', '1.8', '18', '3');
INSERT INTO `用户表` VALUES ('5', '周润发', '2.2', '20', null);
INSERT INTO `用户表` VALUES ('6', '张家辉', '1.8', '18', '1');
