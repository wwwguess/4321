
inherit NPC;

inherit F_MASTER;

void create()
{
        set_name("常相明",({"master chairman","master","chairman","chang"}));
	set("gender", "男性" );
	set("age", 54);
        set("combat_exp",200000);
        set("int",10);
        set("long",@LONG
他是个博学多才的教授，同学们都很敬佩他。
LONG
);
      set("chat_chance",2);
      set("chat_msg",({
        (: random_move :),
        }));
      set("attitude","peaceful");
      create_family("河海人",5,"校长");
      set_skill("literate",200);
      set_skill("sword",120);
      setup();
      carry_object(__DIR__"obj/chunqiu_pen")->wield();
}
void init()
{
      ::init();
      this_player()->set("marks/河海大学",1);
}
void attempt_apprentice(object ob)
{
     if((int)ob->query_skill("literate",1) < 5 )
     {
             command("say 你应该多学点文化啊，现代社会需要知识啊！");
             command("? "+ob->query("id"));
             return;
        }
     command("recruit "+ob->query("id"));
}
