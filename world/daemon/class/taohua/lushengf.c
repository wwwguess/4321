// lushengf.c     
//write by lysh
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("½�˷�", ({ "lu sheng feng", "feng", "lu" }) );
	set("gender", "����" );
	set("age", 54);
	set("long", 
"���ǻ�ҩʦ�������ӣ����һ����Ĵ����\n"
"�¡�÷������½���еĹ�����Ȼ������ߣ�\n"
"�������Ĵ��������Ϊ��ͨ���Ű��Ե�һ����\n" 
"����������ʮ���꣬��ɫ�ݻƣ��ƺ����ز���\n"
"������ߡ������³���һ�����ȡ�\n");
      
	set("title", RED "�һ���" NOR + GRN +"����" NOR);
        set("gender", "����");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 24);
        set("dex", 28);
	set("per", 20);

        set("max_kee", 500);
        set("max_gin", 360);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);
	set("combat_exp", 100000);
        set("score", 2000);

        set("chat_chance_combat", 80);

	set_skill("literate", 70);
	set_skill("qimen-bagua", 70);
        set_skill("force", 70);
	set_skill("taohua-force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("yuxiao-jian", 70);
	
	set_skill("baguabu", 70);
        set_skill("hand", 70);
        set_skill("lanhua-shou", 70);
        set_skill("strike", 70);
        set_skill("luoying-zhang", 70);

	map_skill("force", "taohua-force");
        map_skill("parry", "lanhua-shou");
        map_skill("sword", "yuxiao-jian");
        map_skill("dodge", "baguabu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
	
        prepare_skill("strike", "luoying-zhang");
 	prepare_skill("hand", "lanhua-shou");

        create_family("�һ���", 2, "����");

	set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);

      	setup();
        carry_object("/obj/weapon/gangjian")->wield();
        add_money("gold", 1);
}             

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

