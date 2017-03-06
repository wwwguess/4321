#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "�����");
        set("long", @LONG
����У�ڵ�һ���������
	    ��Χ�ܰ�����ֻ����Ҷ���紵����ɳɳ����С�񻶿�Ľ�����
	�紵��������������ģ��о��ر������̧ͷ�������Ƕ�����ͷ
	�Ƿ�����Ӣ�������������������Դ�������˽����ն�Ѫ����
	�磬����Թ������������һ�ж�����ô���ã��������������
	���������Ӵ˵��������������������¡�
	����һ���Ǹ߸ߵ�ͼ��ݣ���������é������ġ�һ���ǹ���¥��
	ǽ�ϵĺ�����������һ�ź������ƵĴ󺣱�(sign).
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        set("exits", ([ /* sizeof() == 2 */
		  "southwest" :__DIR__"downroad",
		  "northeast" :__DIR__"hhu1road1",
	]));

 //       set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

string look_sign(object me)
{
	return "������д�ţ�\n
=========�н�Ц����     �ѲŰ��Ӻ�=========\n
    ���Դ�MUD��Ϸ������ڹ��ļ����ѧԺ\n
             97��Ӧ�ð������ 
\n         �Լ��������78��ͬѧ\n
                                   By Jenny\n
			               1997��7��\n";
}

