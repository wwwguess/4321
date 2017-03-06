// Room: /d/village/home.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ�����ƾɵ�ľ�ݡ�ÿ��ɽ�紵�������ᷢ����֨֨ѽѽ��
���������ϲ���һ��СС�ĳ�����ľ�ݵĺ�����һ�����ɵĻ�԰����
԰�ﴩ���������֮����һ�����̵�С��ƺ�������档
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
	]));
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"smallstorage",
  "south" : __DIR__"littlegarden",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldliu" : 1,
]));
	create_door("south", "ľ��", "north", DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
}
