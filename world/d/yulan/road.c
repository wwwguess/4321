
inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
����һ����ͨ����ʯС������������������ȥ��·������һƬ�������֣���
���紺ʱ�ڣ�������������֦ͷ����������һ����ʯС����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "west" : "/d/road/changsha",
  "northwest" : "/d/road/ryytocs2",
  "northeast" : "/d/yulan/road1",
]));
	setup();
	replace_program(ROOM);
}
