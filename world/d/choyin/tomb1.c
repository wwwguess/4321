// Room: /d/choyin/tomb1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ڲ���������������ô���ʵ��̫�������վ����
���һ��Ҳ�����þִ٣�����Լ�������˵ĸ߶���ô�������ʸ�
�ֲڵĶ��������뿪�����ߵ������Ƚ��٣�¶��һЩ���㣬���߸�����
������������һ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tomb3",
  "west" : __DIR__"tomb2",
  "up" : __DIR__"tree_tomb",
]));
	set("objects", ([
		__DIR__"npc/shadow": 3
	]) );

	setup();
	replace_program(ROOM);
}
