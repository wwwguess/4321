// fengbuping.c -�ⲻƽ
#include <ansi.h>
inherit NPC;
int ask_xueyi();

void create()
{
        set_name("�ɲ���",({"cheng buyou","chen","buyou"}));
	set("title", GRN "��ɽ" NOR + YEL "����" NOR + CYN "����" NOR);
        set("long",
                "��ɽ�ɽ��ڴ��ˡ�\n"
                "���ǻ�ɽ���ڵĵ�һ���֡�����֮������һ��Ϳ�أ��ⲻƽ���ӿ�������\n");
        set("gender", "����");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_kee",  2000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 100);
        set_skill("huashan-neigong", 100);
        set_skill("dodge", 120);
        set_skill("huashan-shenfa", 120);
        set_skill("parry", 120);
        set_skill("sword", 130);
        set_skill("huashan-jianfa", 120);
        set_skill("strike", 100);
        set_skill("hunyuan-zhang", 100);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("��ɽ��" , 18, "����");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
