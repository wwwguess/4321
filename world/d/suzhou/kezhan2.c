//ROOM:/d/suzhou/kezhan2.c
//by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "�͵��Ժ" NOR);
	set("long", @LONG
	���ǿ�ջ�ĺ�Ժ��������Ӱ��涣�һЩ������Ů��������һ������˽���
��������ۺ첻�ѡ������ר��Ϊ���˿ɵĿͷ����ұ���ΪŮ�˿��ġ�������Ϊ����
�ǿ��ģ��Ǻǡ�
LONG
	);

	set("no_fight", 0);
	set("valid_startroom", 0);
        set("no_sleep_room",1);

	set("exits", ([
		"north" : __DIR__"kefang1",
		"south" : __DIR__"kefang2",
		"east" : __DIR__"kefang3",   
		"west" : __DIR__"kezhan",
	]));

	setup();
}       
  

int valid_leave(object me, string dir)
{
    object *inv;
    mapping mygen;
    int i;
        
	   if (dir == "south" && ((string)me->query("gender") =="����") && !wizardp(
me))
                return notify_fail("�������ү�Ƕ�ȥ�Ǹ����\n");
        return 1;       

   if (dir == "north" && ((string)me->query("gender") =="Ů��") && !wizardp(
me))
                return notify_fail("���СŮ����ȥ�Ǹ����\n");
        return 1;
	                                                    
}


