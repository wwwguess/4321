// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("Ѿ��", ({ "ya huan", "ya" , "huan" }));
	set("title","�Ź־���");
	set("long",
	"һ�����˼ҵ�СѾ�ߣ�����һ˫�������ǵ��۾���\n");
	set("gender", "Ů��");
	set("age", 13);
	set("attitude", "peaceful");
	set("str", 10);
	set("int", 10);
	set("con", 10);
	set("dex", 10);
	set("per", 30);
	set("combat_exp", 500);
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		"СѾ�ߴ����޵�������������ɱ������.��\n",                
        }) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
