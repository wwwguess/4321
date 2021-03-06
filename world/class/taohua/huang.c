// huang-yaoshi.c -黄药师

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void consider();

void create()
{
	set_name("黄药师", ({ "huang yaoshi", "huang", "yaoshi" }) );

	set("nickname",  RED "东邪" NOR);
	set("title", GRN "桃花岛主" NOR);
	set("gender", "男性");
	set("age", 60);
	set("long",
                "他是当今武林泰斗之一，号称东邪。\n"
                "此人据说性格古怪，很难接近。\n"
	);
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("force", 3000);
	set("max_force", 3000);
	set("force_factor", 100);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
	set("max_kee", 5000);
	set("max_gin", 500);

	set("combat_exp", 1500000);
	set("score", 200000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
	


        set_skill("force", 150);
	set_skill("taohua-force", 150);
        set_skill("dodge", 150);
        set_skill("baguabu", 150);
        set_skill("strike", 150);
        set_skill("luoying-zhang",100);
        set_skill("hand",100);
        set_skill("lanhua-shou", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("yuxiao-jian", 150);
        set_skill("literate", 200);
       	set_skill("qimen-bagua", 150);

        map_skill("force", "taohua-force");
        map_skill("dodge", "baguabu");
        map_skill("hand", "lanhua-shou");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        prepare_skill("hand","lanhua-shou");
        prepare_skill("strike", "luoying-zhang");

        create_family("桃花岛", 1, "开山祖师");
        set("class", "平民");

        setup();
        carry_object("/obj/weapon/yuxiao")->wield();
}



void attempt_apprentice(object ob)  
{       
         if ((string)this_player()->query("family/family_name")=="桃花岛")
         {if (this_player()->query_skill("qimen-bagua",1)<80)
            { command("say 我门派不传之密奇门八卦,你领悟不够。");
             return;
             }
            else {command("say 好吧，我就收下你了。");
                 command("recruit " + ob->query("id"));
                 }
          }
         
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        	if((string)ob->query("gender")!="女性")
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"弟子" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"女弟子" NOR);
			return;
		}
       
}
void re_rank(object student)
{
        if (student->query("age")<20)
        {
        	if((string)student->query("gender")!="女性")
		{
                	student->set("title",RED "桃花岛" NOR + GRN +"小童" NOR);
			return;
		}
        	else
		{
                	student->set("title",RED "桃花岛" NOR + GRN +"女童" NOR);
			return;
		}
        }
        else 
	{
        	if((string)student->query("gender")!="女性")
                {
			student->set("title",RED "桃花岛" NOR + GRN +"弟子" NOR);
			return;
		}
	        else
                {
			student->set("title",RED "桃花岛" NOR + GRN +"女弟子" NOR);
			return;
		}
        }
}

void init()
{
 add_action("give_quest","quest");
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
     
        command("exert tanzhi " + target->query("id"));
}

/*void init()
{
	::init();
        add_action("give_quest", "quest");
}
*/
// if not allow quest ,then return 0
//int valid_quest() {
//	return 1;
//}


// check if bribe is valid
int valid_bribe(object who,int val) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： ？！\n",who);
	return(0);
}

// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}


