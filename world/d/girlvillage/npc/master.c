// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string  summon_more( object who);

void create()
{
         set_name("姬九阴", ({ "master ninemoon", "master", "ninemoon" }) );

         set("title", "九阴派掌门");
        set("nickname", "九阴仙子");
        set("gender", "女性");
        set("age", 16);
        set("long",
"姬九阴看上去是一个十分出色的美女，她的九阴白骨爪向来没有过敌手。\n"
                );
        set("attitude", "peaceful");
        set("class", "ninemoon");
        set("apprentice_availqable", 2);
        create_family("九阴派", 81, "掌门");
        set("int", 28);
        set("spi", 26);
        set("per", 30);
        set("cps", 30);
        
        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 18);
        
        set("combat_exp", 1000000);
        set("score", 90000);
        
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("throwing", 100);
        set_skill("force", 90);
        set_skill("parry", 100);
        set_skill("dodge", 100);
 
        set_skill("literate", 100);
        set_skill("perception", 100);
        
        set_skill("nine-moon-steps", 150);
        set_skill("nine-moon-claw", 150);
        set_skill("nine-moon-force", 100);
        set_skill("nine-moon-sword", 100);
        
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");
        
        set_temp("apply/defense", 100);
        
        setup();
        carry_object("/obj/cloth")->wear();
        
        
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 10);
}

void attempt_apprentice(object ob)
{
//        if( query("apprentice_available") ) {
//                if( find_call_out("do_recruit") != -1 )
//                        command("say 慢著，一个一个来。");
//                else
                        call_out("do_recruit", 2, ob);
//         } else {
//                 command("say 本掌门今天已经收了两个弟子，不想再收徒了。");
//         }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" )
          {      command("say 大胆！来人哪！");
                summon_more(this_object());
          }
        else {
        if( ((int)ob->query("cor") < 25) || ((int)ob->query("cps") < 25)
|| ((int)ob->query("int") < 25)
        ||      ((int)ob->query("con") < 25)) {
        command("say 入九阴要靠缘份，依我看" +
RANK_D->query_respect(ob) + "和九阴今生无缘。");
                return;
         }
                command("smile");
                command("say 很好，很好，很好。");
                command("recruit " + ob->query("id") );
         }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "ninemoon");
        add("apprentice_availavble", -1);
}
string summon_more(object who)
{
        int i;
        object *enemy;
        object another;
        if((string) environment(who)->query("outdoors") == "girlvillage")
        {
        seteuid(getuid());
        another = new(__DIR__"thousand_hand");
        another->move(environment(who));
        message_vision(another->name()+ "走了过来。\n"
                , this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        another->kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(another);
                        else enemy[i]->kill_ob(another);
                } 
        }
        set_leader(who);
        return "1";
        }
        else
        return "0";
        
        
}
                                                                                                                                                                         
