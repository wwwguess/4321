
inherit ROOM;

void create()
{
	set("short", "����ɽׯ��Ժ");
	set("long", @LONG
��������ɽׯ�ĺ�Ժ��Ժ�����ż����������������������ɽׯ��
����������ï�ܵ��������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : "/d/yulan/xiaoyuan",
	"west" : "/d/yulan/yulanhall",
	"north" : "/d/yulan/yulanlin",
	"south" : "/d/yulan/houting",
]));

	setup();
	replace_program(ROOM);
}
