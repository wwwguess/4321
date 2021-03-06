#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_xiao();
int ask_me();
void heal();

void create()
{
        set_name("杨过", ({ "yang guo", "yang" }));
       set("nickname", GRN "神雕" NOR+RED "大侠" NOR);

        set("long",
                "他就是大名鼎鼎的神雕大侠杨过。人称西狂。\n"
                "身穿一件干干净净的灰色长袍。\n"
                "年纪在四十岁左右，身材魁梧，脸色凝重。\n");
        set("title",YEL "西狂" NOR);
        set("gender", "男性");
        set("age", 42);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
            set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("max_kee", 10000);
        set("max_gin", 5000);
        set("force", 10000);
        set("max_force", 10000);
        set("jiali", 100);
        set("combat_exp", 3000000);
        set("score", 1000000);

        set("chat_chance", 100);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.wujian" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 300);
        set_skill("anran-zhang",200);
        set_skill("jiuyin", 300);
	set_skill("move", 200);
        set_skill("dodge", 210);
        set_skill("zhuifeng-liushi", 210);
           set_skill("strike", 200);
        set_skill("gumu-xinfa",150);
        set_skill("parry", 210);
        set_skill("sword", 250);
      set_skill("xuantie-jianfa", 250);
      set_skill("literate", 100); 
      set_skill("hama-gong",100);
      set_skill("staff",100);
      set_skill("dagou-bang",100);
        map_skill("force", "jiuyin");
        map_skill("dodge", "zhuifeng-liushi"); 
        map_skill("staff","dagou-bang");
           map_skill("strike", "anran-zhang");
      map_skill("parry", "xuantie-jianfa");
      map_skill("sword", "xuantie-jianfa"); 
     prepare_skill("strike", "anran-zhang");


        create_family("古墓派", 5, "弟子");

        set("inquiry", ([
                "小龙女" : (: ask_xiao :),
                "她在哪儿" : (: ask_me :),
        ]));

        set("book_count", 1);

        setup();
      carry_object("/d/quanzhou/npc/obj/xtsword")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
           if ((string)ob->query("gender")=="无性")
	{
		command("say 你是无性之人,无法练我派的功夫! \n");
		return;
	}
        if ((int)ob->query("shen") <100000) {
                command("say 我古墓派乃是堂堂名门正派，对弟子要求极严。\n");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？\n");
                return;
        }                                                
       if ((int)this_player()->query_temp("marks/杨3")!=1){
              command("say 这位，" + RANK_D->query_respect(ob) + "似乎与我无缘! \n");
               return;
       }    
        command("say 好吧，我就收下你了。\n");
         this_player()->set_temp("marks/杨3",0);
        command("recruit " + ob->query("id"));
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "古墓派" NOR + GRN +"弟子" NOR);
        else
	        this_player()->set("title",RED "古墓派" NOR + GRN +"女弟子" NOR);
}                               
int ask_xiao()
{    
    say(YEL"杨过诧异地说道:她是我的妻子!你认识她? \n"NOR);
      this_player()->set_temp("marks/杨1", 1);
return 1;
}
int ask_me()
{      if((int)this_player()->query_temp("marks/杨1")){
     say(YEL"自从绝情谷一别,悠悠一十六栽,龙儿你在哪儿? \n"NOR);
      command("sigh \n");
        this_player()->set_temp("marks/杨1", 0);
       this_player()->set_temp("marks/杨2", 1);
     return 1;
} } 
 int accept_object(object ob,object what)
{       
        

     if( (string)what->query("name") == "玉蜂" && (int)this_player()->query_temp("marks/杨2") && !userp(what)){
                        say("杨过说道：你从哪儿搞到的?这是龙儿的玉蜂.噢?这玉蜂似乎\n"
                            "有些蹊跷.你看它的翅膀,好象上面有字!左边是:我在绝,右边\n"
                            "是:情谷底.难道是龙儿刺的?难道龙儿她在还在绝情谷底?啊!\n"
                            "这位," + RANK_D->query_respect(ob) + ",太感谢你了!\n"
                            "有什么要求尽管提,我尽量满足你. \n");
                        this_player()->set_temp("marks/杨2",0);
                        this_player()->set_temp("marks/杨3", 1);
                        return 1;
                } 
                
                       
       else {command("nod ");
        return 1; }
}
/*void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <0 && ((fam = ob->query("family")) && fam["master_id"] == "song yuanqiao"))
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		
       */
/*void heal()
{
        object ob=this_object();

        if (ob->query("eff_qi") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 50");
                return;
        }

        if (ob->query("kee") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_jing"))
                command("exert regenerate");

        return;
}      */
