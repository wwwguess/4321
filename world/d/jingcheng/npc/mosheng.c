// Created by ysgl
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC;

#include "namedata.h"

void create()
{                    
	string name = comm_man_name();
	set_name("İ����"+name, ({ "mosheng ren" , "ren"  }));
	switch( random(2) ){
	case 0:
		set("long",
		"����ǰ�϶�û��������ˣ�����Ŀİ����˵��������������ο͡�\n");
		set("gender", "����");
		break;
	default:
		set("long",
		"����ǰ�϶�û��������ˣ�����Ŀİ����˵��������������ο͡�\n");
		set("gender", "Ů��");
		break;
	}
	set("age", 12+random(48));
	set("attitude", "peaceful");
	set("combat_exp", random((int)this_object()->query("age")*300));
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: random_move :),
        }) );
		
	carry_object(__DIR__"obj/cloth")->wear();
}

