
inherit ROOM;

void create()
{
	set("short", "����ɽׯ����");
	set("long", @LONG
��������ɽׯ���������������ܷ��ź�ľ���ӣ������ϰڷ��Ź���������
�������ŷ���һ��������ʯ��, ʯ���Ϸ���һ���������������
����������ɽׯ���ţ�����������ɽׯ��Ժ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : "/d/yulan/yulanc",
	"west" : "/d/yulan/yulan",
	"north" : "/d/yulan/woshi",
	"south" : "/d/yulan/shufang",
]));
	set("objects", ([
                __DIR__"obj/yulan" : 1,
]));

	setup();
	replace_program(ROOM);
}
