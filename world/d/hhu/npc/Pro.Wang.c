
inherit NPC;

string answer_2();
string answer_3();

void follow_player();

void create()
{
        set_name("王教授",({"pro_wang","teacher"}));
	set("title", "教授");
	set("gender", "男性" );
	set("age", 47);
        set("combat_exp",1800);
        set("int",10);
        set("long",@LONG
他是个博学多才的教授，同学们都很敬佩他。
LONG
);
      set("chat_chance",10);
      set("chat_msg",({
         "王教授问：你有什么问题要请教我？\n",
         "王教授说：有什么事情以后再说吧，我要去上课了。\n",
        }));
      set("attitude","friendly");
      set("inquiry", ([
          "1+1" : (: answer_2 :),
          "1+2" : (: answer_3 :),
      ]) );
      set_skill("literate",150);
      set_skill("throwing",80);
      setup();
      carry_object(__DIR__"obj/chalk")->wield();
}

string answer_2()
{
      return "这么简单的问题也问我,1+1=2嘛!真笨! \n";
}

string answer_3()
{
      return "这个问题比较难,需要研究研究,过两年再告诉你!\n";
}
