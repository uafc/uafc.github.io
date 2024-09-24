/** @type {import('tailwindcss').Config} */
export default {
	content: ['./src/**/*.{astro,html,js,jsx,md,mdx,svelte,ts,tsx,vue}'],
	theme: {
		extend: {},
	},
	plugins: [
		require('daisyui'),
	],
	daisyui: {
		darkTheme: "light",
	   },
	//    above code reverts back to light mode, in daisyUI the defauly is dark mode
}
