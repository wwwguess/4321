// Room: /u/k/karrimor/temple/sroad.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʵ����ʯ���, �������ɽ��������ɽ������, ��
����һ��ʯӢ��ʯ��������ɽ�϶�ȥ����ʯ�׵ľ�ͷ, ��һ����Ϊ��ΰ
�ĵ���, �ڽ����ܹ����˶�֪��, ����éɽ�ɵ����ڵء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "westup" : __DIR__"ladder5",
//  "east" : "/d/waterfog/sroad3",
     "east"   : "/d/snow/eroad3",
]));
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
