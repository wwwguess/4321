// Created by lysh
// data: 1997.10.17
              
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("ũ��", ({ "nong min" , "min" }));
	set("long",
	"һ�������ũ��\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("combat_exp", 50);
	setup();
        set("chat_chance", 10);
	set("chat_msg", ({
        	"ũ���ϵ����󣺡�����ү������ɣ�ׯ�ڿ�Ҫ�����ˣ�\n",	
                "ũ���ģ�������үҪ�Ǹ���������ʱ�꣬�Ҿ͸����޽���\n",   
        }) );
        carry_object(__DIR__"obj/suoyi")->wear();

}

