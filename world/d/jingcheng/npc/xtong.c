// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("Сͯ", ({ "xiao tong", "xiao" ,"tong" }));
	set("title",GRN"������"NOR);
	set("long",
	"����������Сͯ������С�ʹ�����书���ף��������¶��е㹦��\n");
	set("gender", "����");
	set("age", 7);
	set("attitude", "heroism");
	set("str", 15);
	set("int", 15);
	set("con", 15);
	set("dex", 15);
	set("combat_exp", 200);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"Сͯһ������һ�ߺ��������ˣ�������\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
