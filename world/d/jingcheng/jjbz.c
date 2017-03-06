// Room: /d/jingcheng/jjbz.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m╪ж╪р╧Юлю╟Эвсфл[2;37;0m");
	set("long", @LONG
╪ж╪р╧Юлю╟Эвсси╪жйопж╣эхЩхкй╪╢╢ё╛й╝╤ЮдЙю╢р╡тзЁ╓╟╡╫Аобакхкт╣║ё
лА╣╫╧Юлю╟Эвсё╛Ё╓╟╡ЁгюО╣дхк╤╪╩Ак╣╪ж╪р╣д╣зр╩║ёнщюО╟зиХ╦и╬╩ё╛й╝
╪╦уе╟коивюсппРееапё╛╪╥бЗакЁт©м║ё
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ql2",
  "north" :__DIR__"chuf",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jia" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
