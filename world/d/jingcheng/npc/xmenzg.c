inherit NPC;
#include <ansi.h>

void create()
{
    set_name("������", ({ "zhao qixian", "zhao" }));

   set("title",GRN "����" NOR + YEL +"�ܹ�" NOR);
        set("long",
"�������������ǵ��Ĵ��ܹ�֮һ�������͡�\n");
        set("gender", "����");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 2000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 30);
        set("combat_exp", 800000);
        set("score", 5000);

        set_skill("force", 120);
        set_skill("dodge", 150);
        set_skill("parry", 120);
        set_skill("sword", 140);
        set_skill("taxue-wuhen", 120);
        set_skill("xiaoyao-jian", 150);
        set_skill("xiaoyao-zhang", 150);
        set_skill("strike", 120);
        set_skill("literate", 110);
    set_skill("hunyuan-yiqi", 150);

 map_skill("force", "hunyuan-yiqi");
        map_skill("parry", "xiaoyao-jian");
        map_skill("sword", "xiaoyao-jian");
        map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "xiaoyao-zhang");




        setup();
carry_object(__DIR__"obj/changjian")->wield();
carry_object(__DIR__"obj/qingshan")->wear();

}

