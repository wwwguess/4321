
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ԭ���ǿ��⡣����İ�����İ���������ֵ��
һȥ���������ˡ������Ҳ����һ�����µġ�
����������ȥ�����������ݡ����Ͼ͵�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rkftodk0",
	"south" : "/d/road/rhktokf4",
	"west" : "/d/road/rjdtoly0",
	"east" : "/d/road/rxztokf3",
]));

	setup();
	replace_program(ROOM);
}
