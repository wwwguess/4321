//old_sword.c

#include <ansi.h>

inherit ITEM;
//inherit F_UNIQUE;

void create()
{
    set_name( "����Ҫּ", ({ "parrybook","pbook" }) );
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
����һ�����ܹ���ʱ��β���ж�����鼮��
����������˵�Ǳ����ɶ�õ��䱦��
LONG
		);
		set("value", 100);
    		set("material", "paper");
		set("skill", ([
        		"name" :        "parry",
            		"exp_required" :  15000,
            		"sen_cost" : 30,
                    	"difficulty" : 25,
            		"max_skill" : 50
			]) );
        	set("replica_ob", __DIR__"cola");
		}
}
		
