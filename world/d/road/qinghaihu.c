
inherit ROOM;

void create()
{
	set("short", "�ຣ��");
	set("long", @LONG 
��������й�������½�������ຣ��������ĺ�ˮ���̣�
���޷��ȵġ�ԶԶ�������ȥ�����ε�㣬����ʲô������
���Ϸ������ͨ��������ʿ̸��ɫ������޺�� ������Ҫ������ɽ�ˡ�
��Ȼ��Զ����Ҳ����ϡ����ΡΡ����ɽ�İ�����ѩ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/xingxiu/rqhhtolz0",
	"southwest" : "/d/road/rqhhtoxsh0",
	"west" : "/d/road/rqhhtokl0",
]));

	setup();
	replace_program(ROOM);
}
