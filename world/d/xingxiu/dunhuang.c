
inherit ROOM;

void create()
{
	set("short", "�ػ�");
	set("long", @LONG
�������˿��֮·�ϵ�����ػ�.�������߾��Ǵ�ɳĮ��,������
������,����˿��֮·�����Źص�һ����,·��������.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northwest" : __DIR__"rdhtoym0",
	"west" : "/d/road/dhshamo",
	"southeast" : __DIR__"rjygtodh2",
]));

	setup();
	replace_program(ROOM);
}
