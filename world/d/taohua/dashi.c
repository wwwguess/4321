// Room: /d/new_taohua/dashi.c

inherit ROOM;

void create()
{
	set("short", "��ʯ");
	set("long", @LONG
�����ǰ��һ���ʯ������԰�������Ǻ�ˮ�������Ľ����
����һʯ��������ʯ�ʡ�ʯ�²�ʱ�о����������ﲨ����ӿ��
�������İ�֮�������Ԥ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  

  "east" : __DIR__"wangluting",
 
]));
	set("outdoors", "new_taohua");

	setup();
	replace_program(ROOM);
}
