#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬����");
	set("long", @LONG
����������Ľ�����������ǰ�������ϰ��Ÿ�ʽˮ��
��һ��Сͭ¯��ͭ¯�������֧�����˵��㡣������ǽ�϶�
û���κζ�����ȴ��ˢ�úܰס�����������һ������¯��
һλò�����˵ĵ�ʿ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"da_yuan",
]));
        set("valid_startroom", 1);
	set("objects", ([
                "/d/taoguan/npc/up_taoist" : 2,
                CLASS_D("taoist")+"/taolord" : 1 ]) );
	setup();
}

