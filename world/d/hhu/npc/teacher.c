
inherit NPC;

void follow_player();

void create()
{
	set_name("张教授",({"pro_zhang","teacher"}));
	set("title", "教授");
	set("gender", "男性" );
	set("age", 47);
        set("combat_exp",2000);
        set("int",10);
        set("long",@LONG
他是个博学多才的教授，同学们都很敬佩他。
LONG
);
      set("env/wimpy",50);
      set("chat_chance",10);
      set("chat_msg",({
         "张教授问：你有什么问题要请教我？\n",
         (: random_move :),
         "张教授说：有什么事情以后再说吧，我要去上课了。\n",
        }));
      set("attitude","peaceful");
      set_skill("literate",140);
      set_skill("sword",80);
      setup();
      carry_object(__DIR__"obj/pen")->wield();
}
