
inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ǳ���ɽ����ڡ�����ɽ�б�Ϫ���ȣ���ľ�Դ䣬�����������������ޡ�
������ľ������ɽ�У�����ԴӴ��Ӻ����Ķ��״������л��������˲Ρ�
¹�׺���Ƥ��Ҳ�����Լ�ȥ���ԣ�������������ˣ�����ɽ��ҩȪ�������˵�
������������һƬ��ɭ�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : "/d/road/rfttocbs2",
	"west": "/d/xueshan/start",
]));

	setup();
	replace_program(ROOM);
}
