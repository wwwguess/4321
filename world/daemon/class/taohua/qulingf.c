// qulingf.c -��ҩʦ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void consider();

void create()
{
	set_name("�����", ({ "quling feng", "feng", "quling" }) );

	set("nickname",  RED "�һ���" NOR);
	set("title", GRN "�����" NOR);
	set("gender", "����");
	set("age", 40);
	set("long",
            "���ǻ�ҩʦ���ĵ��ӣ����һ����Ĵ����\n"
	    "���¡�÷������½���е�����磬���\n"
            "��ҩʦ�谮��������ã�����Ҳ��ߣ�\n"
            "�����黭�������ܡ�����������ʮ���꣬\n"
	    "��ò������������� �е���ġ�\n" 
	);
	set("attitude", "peaceful");

	set("str", 20);
	set("con", 20);
	set("int", 20);
	set("dex", 20);
	set("per", 28);

	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_kee", 2000);
	set("max_gin", 1000);

	set("combat_exp", 500000);
	set("score", 20000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
	


        set_skill("force", 110);
	set_skill("taohua-force", 110);
        set_skill("dodge", 110);
        set_skill("baguabu", 110);
        set_skill("strike", 100);
        set_skill("luoying-zhang",110);
        set_skill("hand",100);
        set_skill("lanhua-shou", 110);
        set_skill("parry", 110);
        set_skill("sword", 100);
        set_skill("yuxiao-jian", 100);
        set_skill("literate", 50);
        set_skill("qimen-bagua", 100);

        map_skill("force", "taohua-xf");
        map_skill("dodge", "baguabu");
        map_skill("hand", "lanhua-shou");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        
        prepare_skill("hand","lanhua-shou");
        prepare_skill("strike", "luoying-zhang");

        create_family("�һ���", 2, "�����");
        set("class", "ƽ��");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
}



void attempt_apprentice(object ob)  
{       
         if ((string)this_player()->query("family/family_name")=="�һ���")
         {if (this_player()->query_skill("qimen-bagua",1)<50)
            { command("say �����ɲ���֮�����Ű���,�����򲻹���");
             return;
             }
            else {command("say �ðɣ��Ҿʹ�ʦ���������ˡ�");
                 command("recruit " + ob->query("id"));
                 }
          }
         
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        	if((string)ob->query("gender")!="Ů��")
                {
			ob->set("title",RED "�һ���" NOR + GRN +"����" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "�һ���" NOR + GRN +"Ů��" NOR);
			return;
		}
       
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        
        command("exert tanzhi " + target->query("id"));
}
