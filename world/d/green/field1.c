// Room: /d/green/field1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���Ŀյ�");
	set("long", @LONG
����һƬ�����յأ����ܶ���һЩ�и�����Ĵ�ʯ�����ʯ��������
ȥ���ǲ�ʯ�������ʵ�ʯ赾�������Ĳ����Ѿ�������ԭ����ģ���ˡ���
�Ͽ�ȥ��һЩ��С�ķ���ʹ��湤�ߵĵط��������Ǵ��ڵĹ㳡��������
���㳡�ĵط���һ����ª����լ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/green/field0",
  "south" : "/d/green/station1",
  "north" : "/d/green/house3",
]));
	set("objects", ([
	"/d/green/npc/kid1" : 1,
	]) );
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
