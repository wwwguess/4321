
inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
������һ��������൱Ǭ�����鷿����ľ����������������Ե�ʮ��
���������������һ����ܣ��������һ���ŵĹ��飬�����߳����ſ�
�Կ���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" : "/d/yulan/yulanhall",
]));

	setup();
	replace_program(ROOM);
}
