
inherit ROOM;

void create()
{
	set("short", "���ݳ���");
	set("long", @LONG
������Ǻ����ˣ������߾ͽ����ˡ�����������ʮ�����֡�
���Ͼ�Ҫ��������ɽ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rhztosz2",
	"south": "/d/road/rfztoyt4",
	"southwest" : "/d/road/rhztoyt0",
]));

	setup();
	replace_program(ROOM);
}
