
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ݹųǣ������Ǳ��ұ���֮�ء�
��������Ͼ͵����꣨�Ͼ�����������ȥ����������

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rjntoxz2",
	"west" : "/d/road/rxztokf0",
	"south" : "/d/road/rxztodk0",
]));

	setup();
	replace_program(ROOM);
}
