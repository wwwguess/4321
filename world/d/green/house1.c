// Room: /d/green/house1.c

inherit ROOM;

void create()
{
	set("short", "�����ļ�");
	set("long", @LONG
����һ����ͨ����լ����С����������ض���һ���ŵ�ʯ�壬ǽ����
������ʽ�����ĵ�̣��и�Ĺ��ߡ��ݽǷ�����ʽ�ĳ�Ʒ�����Ʒ��ʯ��
��ʯ�Ρ�Ĺ���ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/green/path8",
]));
	set("objects", ([
	"/d/green/npc/worker1" : 1,
	]) );


	setup();
	replace_program(ROOM);
}
