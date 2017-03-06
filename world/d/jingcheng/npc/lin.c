// lin.c ���ϰ�
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIR"���ϰ�"NOR, ({ "lin laoban", "lin" }));
	set("title", HIB"�Ŷ����ϰ�"NOR); 
	set("shen_type", 1);

	set("str", 25);
	set("gender", "����");
	set("age", 40);
	set("long", "���ϰ徭Ӫ�洫�����ĹŶ������ж��ꡣ\n");
	set("combat_exp", 50000);
        set("kee", 300);
        set("max_kee", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ([
               "��䱭": __DIR__"obj/cup.c",
               "�����": __DIR__"obj/hsbi.c",    
	"��������":	__DIR__"obj/horse.c",
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                "����㿴��������û������Ķ�����\n", 
		"����ĹŶ����ǻ����ʵ�ı�������Ҫ���ม�\n",
        }) );

	add_money("gold", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

