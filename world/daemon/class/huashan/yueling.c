// yueling.c 岳灵珊
// 2/15/98 rewrite by solor
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int ask_linghu();
int ask_siguo();

void create()
{
        set_name("岳灵珊",({"yue lingshan","lingshan","yue"}));
        set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
        set("long",
                "华山派掌门岳不群的爱女。\n"
                "她看起来十多岁，容貌秀丽，虽不是绝代美人，也别有一番可人之处。\n");
        set("gender", "女性");
        set("age", 19);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 22);
        set("con", 26);
        set("dex", 26);
	set("per", 22);

        set("max_kee",  500);
        set("max_gin", 300);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 5000);

        set_skill("force", 60);
        set_skill("huashan-neigong", 40);
        set_skill("dodge", 60);
        set_skill("huashan-shenfa", 60);
        set_skill("parry", 55);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 45);
        set_skill("strike", 50);
        set_skill("hunyuan-zhang", 50);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");

        set("chat_chance", 10);
        set("chat_msg", ({
          "岳灵珊低头自言自语说：大师哥现在不知怎么样了？\n",
	"岳灵珊对陆大有说：六师兄，我们该去给大师哥送饭了吧？\n",
        }) );
        create_family("华山派" , 19, "弟子");
        set("inquiry", ([
                "岳不群" : "岳灵珊说：他老人家是我的父亲。\n",
                "宁中则" : "岳灵珊说：她老人家是我的母亲。\n",
                "令狐冲" : (: ask_linghu :),
                "思过崖" : (: ask_siguo :),
        ]) );



        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/greenrobe")->wear();
}
int ask_linghu()
{   object ob;
   //mapping myfam;
  //      if (!(myfam = this_player()->query("family"))
  //          || myfam["family_name"] != "华山派")
   ob = this_player();
   if (ob->query("kar") > 28) 
   {
      say("岳灵珊说：他是我的大师兄，现在正在思过崖思过。\n");
      this_player()->set_temp("marks/令1", 1);
    return 1;    
   }
    if ( random(3)>1 ) 
   {
      say("岳灵珊说：他是我的大师兄，你问他干什么？\n");
      return 1;
   }
  else
   {
      say("岳灵珊说：他是我的大师兄，现在正在思过崖思过。\n");
      this_player()->set_temp("marks/令1", 1);
    return 1;
   }
}

int ask_siguo()
{
  if ((int)this_player()->query_temp("marks/令1")) {
     say("岳灵珊说：思过崖在华山后山。从练武场往西北的小路可以通向思过崖。\n");
     this_player()->set_temp("marks/思1", 1);
     return 1;
  }
  else {
     say("岳灵珊说：思过崖是华山重地，你怎么知道的？\n");
     return 1;
  }
}
void attempt_apprentice(object ob)
{
        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
        else if ((string)ob->query("gender")=="无性" && ob->query_skill("pixie-jian")>=50)
        {
                command("say 我看你向东厂派来的奸细。");
                return;
        }
        if((string)ob->query("gender")=="女性")
          {
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));

           }
        else {
          command("say 我不收男弟子。"+RANK_D->query_respect(ob)+"你还是去拜我师兄吧！\n");
            };
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<=-100 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "yue lingshan"))
        {
                command("say 你多次杀害好人，还屡教不改，我岂能仍是你的师傅。\n");
		ob->set("bad", 0);
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("age")<20)
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"女剑童" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"女剑士" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("age")<20)
                {
                        student->set("title",GRN "华山派" NOR + YEL +"女剑童" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "华山派" NOR + YEL +"女剑士" NOR);
                        return;
                }
}
